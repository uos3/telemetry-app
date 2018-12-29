#include "spec.h"

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

	// single value.
	if (length == 1) {
		return QVariant(static_cast<T>(b.get(bits)));
	}

	// multiple values -- array.
	//   - fixed size, but not known at compile-time -- vector.
	//   - want easy integration with QVariant without messing about with custom metatypes -- QList.
	//   - easy serialisability to a json list -- QVariantList.
	/* TODO #remove */
	/* QList<T> a; */
	/* a.reserve(length); */
	/* for (int i = 0; i < length; i++) { */
	/* 	a.push_back(static_cast<T>(b.get(bits))); */
	/* } */

	QList<QVariant> a;
	a.reserve(length);

	for (int i = 0; i < length; i++) {
		a.push_back(QVariant(static_cast<T>(b.get(bits))));
	}

	return QVariant::fromValue(a);
}

template<>
QVariant get_variant<char> (Buffer& b, int bits, int length) {
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

	QJsonObject field_type = field_spec["type"].toObject();

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

	if (name == "int") {
		if (signed_data) {
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
	} else if (name == "float") {
		return get_variant<float>(b, 32, length);
	} else if (name == "char") {
		return get_variant<char>(b, 8, length);
	} else if (name == "bool") {
		return get_variant<bool>(b, 1, length);
	} else if (name == "time") {
		return get_variant<uint32_t>(b, 32, length);
	} else {
		std::string msg = "buffer parsing: unknown data type " + name;
		throw std::invalid_argument(msg);
	}
}

QMap<QString, QVariant> map_from_buffer (Buffer& b, int starting_pos,
                                         const std::string& spec_filename) {
	// parse a buffer into a packet (as a map of std::string : QVariant), as specified by the json in the given
	// filename.

	b.set_pos(starting_pos);

	QJsonObject spec = spec_from_file(spec_filename);

	QMap<QString, QVariant> result;

	QJsonObject fields = spec["fields"].toObject();
	for (const QString& field_name : fields.keys()) {
		result[field_name] = field_value(fields[field_name].toObject(), b);
	}

	return result;
}

/* QJsonDocument map_to_json (std::map<std::string, QVariant> mymap) { */
/* 	QVariantMap varmap; */

/* 	for (auto elem : mymap) { */
/* 		varmap[QString::fromStdString(elem.first)] = elem.second; */
/* 	} */

/* 	QJsonDocument doc = QJsonDocument::fromVariant(varmap); */

/* 	return doc; */
/* } */
