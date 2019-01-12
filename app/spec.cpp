#include "spec.h"
#include "utility.h"

#include <QJsonDocument>
#include <QFile>

#include <exception>

QJsonObject spec_from_file (const std::string& filename) {
	// get the QJsonObject of a packet spec from a given filename.

	QString val;
	QFile file;

	file.setFileName(QString::fromStdString(filename));
	file.open(QIODevice::ReadOnly | QIODevice::Text);

	val = file.readAll();

	file.close();

	QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
	return d.object();
}

QString spec_name (const QJsonObject& spec, const std::string& type, const std::string& default_name) {
	// get the name of a packet specification, from its QJsonObject representation.

	if (spec["name"].isString()) {
		return spec["name"].toString();
	}

	QJsonValue name_value = spec["name"].toObject()[QString::fromStdString(type)];
	if (name_value.isString()) {
		return name_value.toString();
	}

	return QString::fromStdString(default_name);
}

template<class T>
QVariant get_variant (Buffer& b, int bits, int length) {
	// get a certain value from the buffer, and return as a QVariant.

	qDebug() << "\tgetting" << bits << "bits," << length << "time(s).\n";

	// single value.
	if (length == 1) {
		return QVariant(static_cast<T>(b.get(bits)));
	}

	// multiple values -- array.
	//   - fixed size, but not known at compile-time -- vector.
	//   - want easy integration with QVariant without messing about with custom metatypes -- QList.
	//   - easy serialisability to a json list -- QVariantList.

	QList<QVariant> a;
	a.reserve(length);

	for (int i = 0; i < length; i++) {
		a.push_back(QVariant(static_cast<T>(b.get(bits))));
	}

	return QVariant::fromValue(a);
}

template<>
QVariant get_variant<char> (Buffer& b, int bits, int length) {

	qDebug() << "\tgetting" << bits << "bits," << length << "time(s).\n";

	if (length == 1) {
		return QVariant(static_cast<char>(b.get(bits)));
	}

	// Special case: list of chars -> string (mostly for json serialisation).
	QString s;

	for (int i = 0; i < length; i++) {
		s.append(static_cast<unsigned char>(b.get(bits)));
	}

	return QVariant::fromValue(s);
}

QVariant field_value (const QJsonObject& field_spec, Buffer& b) {
	// get the value of a given field in the packet, from the given buffer.

	QJsonObject field_type = QJsonObject();

	if (field_spec.contains("type")) {
		field_type = field_spec["type"].toObject();
	} else if (field_spec.contains("struct") && field_spec["struct"].toObject().contains("type")) {
		field_type = field_spec["struct"].toObject()["type"].toObject();
	} else {
		std::string full_field = QJsonDocument(field_spec)
		                         .toJson(QJsonDocument::Compact).data();
		std::string msg = "buffer parsing: field "
		                  + full_field
		                  + " has no type specified.";
		throw std::invalid_argument(msg);
	}

	qDebug() << "\t" << QJsonDocument(field_spec).toJson(QJsonDocument::Compact).data();

	std::string name = "unnamed";
	if (field_type.contains("name")) {
		name = field_type["name"].toString().toStdString();
	}

	int bits = -1;
	if (field_type.contains("bits")) {
		bits = field_type["bits"].toInt();
	}

	bool signed_data = true;
	if (field_type.contains("signed")) {
		signed_data = field_type["signed"].toBool();
	}

	int length = 1;
	if (field_spec.contains("length")) {
		length = field_spec["length"].toInt();
	}

	// lovely if statements
	if (name == "int" && bits != -1) {
		if (signed_data) {
			// signed int -- get the right type
			if (bits <= 8) {
				return get_variant<int8_t>(b, bits, length);
			} else if (bits <= 16) {
				return get_variant<int16_t>(b, bits, length);
			} else if (bits <= 32) {
				return get_variant<int32_t>(b, bits, length);
			} else {
				throw std::invalid_argument("buffer parsing: can't have ints greater than 32 bits long.");
			}
		} else {
			// unsigned int -- get the right type
			if (bits <= 8) {
				return get_variant<uint8_t>(b, bits, length);
			} else if (bits <= 16) {
				return get_variant<uint16_t>(b, bits, length);
			} else if (bits <= 32) {
				return get_variant<uint32_t>(b, bits, length);
			} else {
				throw std::invalid_argument("buffer parsing: can't have ints greater than 32 bits long.");
			}
		}
	// other built-in types
	} else if (name == "float") {
		return get_variant<float>(b, 32, length);
	} else if (name == "char") {
		return get_variant<char>(b, 8, length);
	} else if (name == "bool") {
		return get_variant<bool>(b, 1, length);
	} else if (name == "time") {
		return get_variant<uint32_t>(b, 32, length);
	// unknown type, but known size -- just interpret as int (or an empty
	// variant if size == 0)
	} else if (bits != -1) {
		b.set_pos(b.get_pos() + bits);
		return QVariant();
		/* TODO #remove */
		/* if (bits == 0) { */
		/* 	return QVariant(); */
		/* } else { */
		/* 	return get_variant<uint32_t>(b, bits, length); */
		/* } */
	// not enough info with which to parse -- throw error
	} else {
		std::string full_field = QJsonDocument(field_spec)
		                         .toJson(QJsonDocument::Compact).data();
		std::string msg = "buffer parsing: unknown data type "
		                  + name + ", " + full_field;
		throw std::invalid_argument(msg);
	}
}

QMap<QString, QVariant> map_from_buffer (Buffer& b, int starting_pos,
                                         const std::string& spec_filename) {
	// parse a buffer into a packet (as a map of std::string : QVariant), as
	// specified by the json in the given filename.

	qDebug() << "\n\nparsing" << QString::fromStdString(spec_filename) << "starting at position" << starting_pos;
	b.set_pos(starting_pos);

	QJsonObject spec = spec_from_file(spec_filename);

	QMap<QString, QVariant> result;

	QJsonObject fields = spec["fields"].toObject();
	for (const QString& field_name : fields.keys()) {
		qDebug() << field_name << ":";
		result[field_name] = field_value(fields[field_name].toObject(), b);
	}

	return result;
}

QMap<QString, QVariant> parse_packet (Buffer& b) {
	// fully parse a packet from a Buffer into a QMap.

	// TODO #bug: the 'packet' part doesn't work (as ever) because 'crc' and
	//            'hash' are read from the end, not from the beginning. only
	//            'payload type' can be read in from position 64. also, the
	//            'downlink time' is generated, not read from the buffer.
	//
	//            kind of tempted to just do the 'packet' part manually, what
	//            with all the specialness.
	QMap<QString, QVariant> result_packet = map_from_buffer(b, 64, "packet.json");
	QMap<QString, QVariant> result_status = map_from_buffer(b, 80, "status.json");

	QString spec_filename = "unknown";
	switch(result_packet["type"].toInt()) {
		case 2://PayloadType::GPS:
			spec_filename = "gps.json";
			break;
		case 3://PayloadType::IMU:
			spec_filename = "imu.json";
			break;
		case 4://PayloadType::Health:
			spec_filename = "health.json";
			break;
		case 5://PayloadType::Img:
			spec_filename = "img.json";
			break;
		case 6://PayloadType::Config:
			spec_filename = "config.json";
			break;
	}
	if (spec_filename == "unknown") {
		std::string msg = "unknown payload type "
		                  + std::to_string(result_packet["type"].toInt())
		                  + ".";
		throw std::runtime_error(msg);
	}

	QMap<QString, QVariant> result_payload = map_from_buffer(
		b, 248, spec_filename.toStdString());

	QMap<QString, QVariant> result = result_packet;
	result["status"] = result_status;
	result["payload"] = result_payload;

	result["downlink_time"] = util::now();

	return result;
}
