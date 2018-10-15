#include "db.h"

DB::DB (std::string hostname, std::string dbname,
        std::string username, std::string password) :
dbname(dbname), hostname(hostname) {
// set up db
	// 'QMYSQL driver not loaded' -> https://stackoverflow.com/a/47334605
	// TODO #enhancement: would prob be better to use sqlite than mysql
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(QString::fromStdString(hostname));
	db.setDatabaseName(QString::fromStdString(dbname));
	db.setUserName(QString::fromStdString(username));
	db.setPassword(QString::fromStdString(password));
	// TODO #bug: db is never closed -- need destructor
	if (db.open()) {
		qDebug("db opened successfully.");
	} else {

        //qDebug(db.lastError()::ErrorType);
        if (db.isOpenError())
        {
            // We had an error opening the database
            // We should try to check to see what the error was and output it as debug

            qDebug("Open DB Error");

            qDebug() << db.lastError().type();

            // 0 = No Error
            // 1 = Connection Error
            // 2 = SQL Statment Syntax Error
            // 3 = Transaction Failed Error
            // 4 = Unknown Error
        }
		qDebug("db failed to open.");
	}
}

QSqlQuery DB::get (QString table, QString field) {
	QSqlQuery query;
	QString full_query_string = "select " + field + " from " + table;
	if (query.exec(full_query_string)) {
		return query;
	} else {
		// TODO #enhancement: can prob deal with this better.
		std::string msg = "error with db query \"" + full_query_string.toStdString()+ "\".";
		throw std::runtime_error(msg);
	}
}

QTableView* DB::table (QString table, QString fields) {
	QSqlQueryModel model;
	model.setQuery("select" + fields + " from " + table);

	QStringList field_list = fields.split(", ");
	for (int i=0; i<field_list.size(); i++) {
		model.setHeaderData(i, Qt::Horizontal, field_list.at(i));
	}

	QTableView* view = new QTableView;
	view->setModel(&model);
	return view;
}

QList<QPair<QString, QString>> DB::row (QSqlQuery qu, QString fields) {
// gives a tuple (for a row) of { "col_name": "value", ... }
// TODO #refactor: necessary?
	QStringList field_list = fields.split(", ");

	QList<QPair<QString, QString>> list;
	for (int i=0; i < field_list.size(); i++) {
		QString col = field_list.at(i);
		QString val = qu.value(i).toString();

		list << qMakePair(col, val);
	}

	return list;
}

// template <class T>
// void DB::add_to_query (QString& query, const T& x, bool comma) {
// 	query += std::to_string(x);
// 	if (comma) { query += ", "; }
// }

bool DB::store_packet (Packet& p) {
	QSqlQuery query;
	QString query_str = "BEGIN;\n";
	QTextStream stream(&query_str);

	// packet
	stream << "INSERT INTO PACKETS (packCHK, packHASH, seqStat, seqPayload, \
		payloadType, downlinkTime) VALUES (" <<
	p.crc << ", " <<
	p.hash << ", " <<
	p.status.sequence_id << ", ";
	switch (p.type) {
		case PayloadType::GPS :
//			query_str += p.payload.gps.sequence_id; comma();
			stream << p.payload.gps.sequence_id << ", ";
//			query_str += static_cast<int>(p.type); comma();
			stream << static_cast<int>(p.type) << ", ";
			break;
		case PayloadType::IMU :
//			query_str += p.payload.imu.sequence_id; comma();
			stream << p.payload.imu.sequence_id << ", ";
//			query_str += static_cast<int>(p.type); comma();
			stream << static_cast<int>(p.type) << ", ";
			break;
		case PayloadType::Health :
//			query_str += p.payload.health.sequence_id; comma();
			stream << p.payload.health.sequence_id << ", ";
//			query_str += static_cast<int>(p.type); comma();
			stream << static_cast<int>(p.type) << ", ";
			break;
		case PayloadType::Img :
//			query_str += p.payload.img.sequence_id; comma();
			stream << p.payload.img.sequence_id << ", ";
//			query_str += static_cast<int>(p.type); comma();
			stream << static_cast<int>(p.type) << ", ";
			break;
		case PayloadType::Config :
//			query_str += p.payload.config.sequence_id; comma();
			stream << p.payload.config.sequence_id << ", ";
//			query_str += static_cast<int>(p.type); comma();
			stream << static_cast<int>(p.type) << ", ";
			break;
		default:
			// TODO #completeness: deal with this better
			qDebug() << "payload type not supported!";
			break;
	}
	stream << p.downlink_time << ");\n";

	// status
	stream << "INSERT INTO STATUS (packID, seqStat, SCID, SCTime, \
	    timeSource, OBCTemp, battTemp, battVolt, battCurrent, chargeCurrent, \
	    antDep, dataPending, rebootCnt, rails1, rails2, rails3, rails4, \
		rails5, rails6, RXTemp, TXTemp, PATemp, RXNoiseFloor) VALUES (" <<
	"last_insert_id(), " <<
	p.status.sequence_id << ", " <<
	p.status.spacecraft_id << ", " <<
	p.status.time << ", " <<
	p.status.time_source << ", " <<
	p.status.obc_temperature << ", " <<
	p.status.battery_temperature << ", " <<
	p.status.battery_voltage << ", " <<
	p.status.battery_current << ", " <<
	p.status.charge_current << ", " <<
	p.status.antenna_deployment << ", " <<
	p.status.data_pending << ", " <<
	p.status.reboot_count << ", " <<
	p.status.rails_status[0] << ", " <<
	p.status.rails_status[1] << ", " <<
	p.status.rails_status[2] << ", " <<
	p.status.rails_status[3] << ", " <<
	p.status.rails_status[4] << ", " <<
	p.status.rails_status[5] << ", " <<
	p.status.rx_temperature << ", " <<
	p.status.tx_temperature << ", " <<
	p.status.pa_temperature << ", " <<
	p.status.rx_noisefloor << ");\n";

	// payload
	switch (p.type) {
		case PayloadType::GPS :
			stream << "INSERT INTO GPS (packID, seqPayload, payloadTimeStamp, \
					lat, lon, alt, HDOP, VDOP, PDOP, TDOP) VALUES (" <<
			"last_insert_id(), " <<
			p.payload.gps.sequence_id << ", " <<
			p.payload.gps.timestamp << ", " <<
			p.payload.gps.lat << ", " <<
			p.payload.gps.lon << ", " <<
			p.payload.gps.alt << ", " <<
			p.payload.gps.HDOP << ", " <<
			p.payload.gps.VDOP << ", " <<
			p.payload.gps.PDOP << ", " <<
			p.payload.gps.TDOP << ");\n";
			break;
		case PayloadType::IMU :
			stream << "INSERT INTO IMU (packID, seqPayload, payloadTimeStamp, \
					magX, magY, magZ, gyroX, gyroY, gyroZ, accelX, accelY, accelZ) \
					VALUES (" <<
			"last_insert_id(), " <<
			p.payload.imu.sequence_id << ", " <<
			p.payload.imu.timestamp << ", " <<
			p.payload.imu.Mag_X << ", " <<
			p.payload.imu.Mag_Y << ", " <<
			p.payload.imu.Mag_Z << ", " <<
			p.payload.imu.Gyro_X << ", " <<
			p.payload.imu.Gyro_Y << ", " <<
			p.payload.imu.Gyro_Z << ", " <<
			p.payload.imu.Accel_X << ", " <<
			p.payload.imu.Accel_Y << ", " <<
			p.payload.imu.Accel_Z << ");\n";
			break;
		case PayloadType::Health :
			stream << "INSERT INTO HEALTH (packID, seqPayload, payloadTimeStamp, \
					OBCTemp, RXTemp, TXTemp, PATemp, rebootCnt, dataPending, antSwitch, \
					RXNoiseFloor, detectFlashErr, detectRAMErr, battVolt, battCurrent, \
					battTemp, chargeCurrent, MPPTVolt, solarN1C, solarN2C, \
					solarE1C, solarE2C, solarS1C, solarS2C, solarW1C, solarW2C, \
					solarT1C, solarT2C, rails1Switch, rails2Switch, rails3Switch, \
					rails4Switch, rails5Switch, rails6Switch, rails1Over, rails2Over, \
					rails3Over, rails4Over, rails5Over, rails6Over, \
					rails1Boot, rails1OverCnt, rails1Volt, rails1Curr, \
					rails2Boot, rails2OverCnt, rails2Volt, rails2Curr, \
					rails3Boot, rails3OverCnt, rails3Volt, rails3Curr, \
					rails4Boot, rails4OverCnt, rails4Volt, rails4Curr, \
					rails5Boot, rails5OverCnt, rails5Volt, rails5Curr, \
					rails6Boot, rails6OverCnt, rails6Volt, rails6Curr, \
					3V3Volt, 3V3Curr, 5VVolt, 5VCurr) VALUES (" <<
			"last_insert_id(), " <<
			p.payload.health.sequence_id << ", " <<
			p.payload.health.timestamp << ", " <<
			p.payload.health.obc_temperature << ", " <<
			p.payload.health.rx_temperature << ", " <<
			p.payload.health.tx_temperature << ", " <<
			p.payload.health.pa_temperature << ", " <<
			p.payload.health.reboot_count << ", " <<
			p.payload.health.data_packets_pending << ", " <<
			p.payload.health.antenna_switch << ", " <<
			p.payload.health.rx_noisefloor << ", " <<
			p.payload.health.detected_flash_errors << ", " <<
			p.payload.health.detected_ram_errors << ", " <<
			p.payload.health.battery_voltage << ", " <<
			p.payload.health.battery_current << ", " <<
			p.payload.health.battery_temperature << ", " <<
			p.payload.health.charge_current << ", " <<
			p.payload.health.mppt_voltage << ", " <<
			p.payload.health.solar_n1_current << ", " <<
			p.payload.health.solar_n2_current << ", " <<
			p.payload.health.solar_e1_current << ", " <<
			p.payload.health.solar_e2_current << ", " <<
			p.payload.health.solar_s1_current << ", " <<
			p.payload.health.solar_s2_current << ", " <<
			p.payload.health.solar_w1_current << ", " <<
			p.payload.health.solar_w2_current << ", " <<
			p.payload.health.solar_t1_current << ", " <<
			p.payload.health.solar_t2_current << ", " <<
			p.payload.health.rails_switch_status[0] << ", " <<
			p.payload.health.rails_switch_status[1] << ", " <<
			p.payload.health.rails_switch_status[2] << ", " <<
			p.payload.health.rails_switch_status[3] << ", " <<
			p.payload.health.rails_switch_status[4] << ", " <<
			p.payload.health.rails_switch_status[5] << ", " <<
			p.payload.health.rails_overcurrent_status[0] << ", " <<
			p.payload.health.rails_overcurrent_status[1] << ", " <<
			p.payload.health.rails_overcurrent_status[2] << ", " <<
			p.payload.health.rails_overcurrent_status[3] << ", " <<
			p.payload.health.rails_overcurrent_status[4] << ", " <<
			p.payload.health.rails_overcurrent_status[5] << ", " <<
			p.payload.health.rail_1_boot_count << ", " <<
			p.payload.health.rail_1_overcurrent_count << ", " <<
			p.payload.health.rail_1_voltage << ", " <<
			p.payload.health.rail_1_current << ", " <<
			p.payload.health.rail_2_boot_count << ", " <<
			p.payload.health.rail_2_overcurrent_count << ", " <<
			p.payload.health.rail_2_voltage << ", " <<
			p.payload.health.rail_2_current << ", " <<
			p.payload.health.rail_3_boot_count << ", " <<
			p.payload.health.rail_3_overcurrent_count << ", " <<
			p.payload.health.rail_3_voltage << ", " <<
			p.payload.health.rail_3_current << ", " <<
			p.payload.health.rail_4_boot_count << ", " <<
			p.payload.health.rail_4_overcurrent_count << ", " <<
			p.payload.health.rail_4_voltage << ", " <<
			p.payload.health.rail_4_current << ", " <<
			p.payload.health.rail_5_boot_count << ", " <<
			p.payload.health.rail_5_overcurrent_count << ", " <<
			p.payload.health.rail_5_voltage << ", " <<
			p.payload.health.rail_5_current << ", " <<
			p.payload.health.rail_6_boot_count << ", " <<
			p.payload.health.rail_6_overcurrent_count << ", " <<
			p.payload.health.rail_6_voltage << ", " <<
			p.payload.health.rail_6_current << ", " <<
			p.payload.health._3v3_voltage << ", " <<
			p.payload.health._3v3_current << ", " <<
			p.payload.health._5v_voltage << ", " <<
			p.payload.health._5v_current << ");\n";
			break;
		case PayloadType::Img :
			stream << "INSERT INTO IMG (packID, seqPayload, payloadTimeStamp, \
					imgID, fragID, fragNums, imgData) VALUES (" <<
			"last_insert_id(), " <<
			p.payload.img.sequence_id << ", " <<
			p.payload.img.timestamp << ", " <<
			p.payload.img.image_id << ", " <<
			p.payload.img.fragment_id << ", " <<
			p.payload.img.num_fragments << ", " <<
			p.payload.img.image_data << ");\n";
			break;
		case PayloadType::Config :
			// TODO #bug: Conf needs finishing
			break;
		default:
			// TODO #completeness: deal with this better
			qDebug() << "payload type not supported!";
			break;
	}

	stream << "COMMIT;";
	qDebug() << query_str;
	return query.exec(query_str);
}

std::string DB::get_name () { return this->dbname; }
std::string DB::get_hostname () { return this->hostname; }
