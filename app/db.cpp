#include "db.h"

DB::DB(std::string hostname, std::string dbname, std::string username, std::string password) {
// set up db
	// 'QMYSQL driver not loaded' -> https://stackoverflow.com/a/47334605
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(QString::fromStdString(hostname));
	db.setDatabaseName(QString::fromStdString(dbname));
	db.setUserName(QString::fromStdString(username));
	db.setPassword(QString::fromStdString(password));
	if (db.open()) {
		qDebug("db opened successfully.");
	} else {
		qDebug("db failed to open.");
	}
}

QSqlQuery DB::get (QString table, QString field) {
	QSqlQuery query;
	QString full_query_string = "select " + field + " from " + table;
	if (query.exec(full_query_string)) {
		return query;
	} else {
		// TODO @enhancement: can prob deal with this better.
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
// TODO @refactor: necessary?
	QStringList field_list = fields.split(", ");

	QList<QPair<QString, QString>> list;
	for (int i=0; i < field_list.size(); i++) {
		QString col = field_list.at(i);
		QString val = qu.value(i).toString();

		list << qMakePair(col, val);
	}

	return list;
}

bool DB::store_packet (Packet p) {
	QSqlQuery query;
	QString query_str = "BEGIN;\n";

	// TODO @refactor: a neater way of doing this?
	auto comma = [&query_str]() { query_str += ", "; };

	// packet
	query_str += "INSERT INTO PACKETS (packCHK, packHASH, seqStat, seqPayload, \
	    payloadType, downlinkTime) VALUES (";
	query_str += p.crc; comma();
	query_str += p.hash; comma();
	query_str += p.status.sequence_id; comma();
	switch (p.type) {
		case PayloadType::GPS :
			query_str += p.payload.gps.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case PayloadType::IMU :
			query_str += p.payload.imu.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case PayloadType::Health :
			query_str += p.payload.health.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case PayloadType::Img :
			query_str += p.payload.img.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case PayloadType::Config :
			query_str += p.payload.conf.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
	}
	query_str += p.downlink_time;
	query_str += ");\n";

	// status
	query_str += "INSERT INTO STATUS (packID, seqStat, SCID, SCTime, \
	    timeSource, OBCTemp, battTemp, battVolt, battCurrent, chargeCurrent, \
	    antDep, dataPending, rebootCnt, rails1, rails2, rails3, rails4, \
	    rails5, rails6, RXTemp, TXTemp, PATemp, RXNoiseFloor) VALUES (";
	query_str += "last_insert_id(), ";
	query_str += p.status.sequence_id; comma();
	query_str += p.status.spacecraft_id; comma();
	query_str += p.status.time; comma();
	query_str += p.status.time_source; comma();
	query_str += p.status.obc_temperature; comma();
	query_str += p.status.battery_temperature; comma();
	query_str += p.status.battery_voltage; comma();
	query_str += p.status.battery_current; comma();
	query_str += p.status.charge_current; comma();
	query_str += p.status.antenna_deployment; comma();
	query_str += p.status.data_pending; comma();
	query_str += p.status.reboot_count; comma();
	query_str += p.status.rails_status[0]; comma();
	query_str += p.status.rails_status[1]; comma();
	query_str += p.status.rails_status[2]; comma();
	query_str += p.status.rails_status[3]; comma();
	query_str += p.status.rails_status[4]; comma();
	query_str += p.status.rails_status[5]; comma();
	query_str += p.status.rx_temperature; comma();
	query_str += p.status.tx_temperature; comma();
	query_str += p.status.pa_temperature; comma();
	query_str += p.status.rx_noisefloor;
	query_str += ");\n";

	// payload
	switch (p.type) {
		case PayloadType::GPS :
			query_str += "INSERT INTO GPS (packID, seqPayload, payloadTimeStamp, \
					lat, lon, alt, HDOP, VDOP, PDOP, TDOP) VALUES (";
			query_str += "last_insert_id(), ";
			query_str += p.payload.gps.sequence_id; comma();
			query_str += p.payload.gps.timestamp; comma();
			query_str += p.payload.gps.lat; comma();
			query_str += p.payload.gps.lon; comma();
			query_str += p.payload.gps.alt; comma();
			query_str += p.payload.gps.HDOP; comma();
			query_str += p.payload.gps.VDOP; comma();
			query_str += p.payload.gps.PDOP; comma();
			query_str += p.payload.gps.TDOP;
			query_str += ");\n";
			break;
		case PayloadType::IMU :
			query_str += "INSERT INTO IMU (packID, seqPayload, payloadTimeStamp, \
					magX, magY, magZ, gyroX, gyroY, gyroZ, accelX, accelY, accelZ) \
					VALUES ("
			query_str += "last_insert_id(), ";
			query_str += p.payload.imu.sequence_id; comma();
			query_str += p.payload.imu.timestamp; comma();
			query_str += p.payload.imu.Mag_X; comma();
			query_str += p.payload.imu.Mag_Y; comma();
			query_str += p.payload.imu.Mag_Z; comma();
			query_str += p.payload.imu.Gyro_X; comma();
			query_str += p.payload.imu.Gyro_Y; comma();
			query_str += p.payload.imu.Gyro_Z; comma();
			query_str += p.payload.imu.Accel_X; comma();
			query_str += p.payload.imu.Accel_Y; comma();
			query_str += p.payload.imu.Accel_Z;
			query_str += ");\n";
			break;
		case PayloadType::Health :
			query_str += "INSERT INTO HEALTH (packID, seqPayload, payloadTimeStamp, \
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
					3V3Volt, 3V3Curr, 5VVolt, 5VCurr) VALUES ("
			query_str += "last_insert_id(), ";
			query_str += p.payload.health.sequence_id; comma();
			query_str += p.payload.health.timestamp; comma();
			query_str += p.payload.health.obc_temperature; comma();
			query_str += p.payload.health.rx_temperature; comma();
			query_str += p.payload.health.tx_temperature; comma();
			query_str += p.payload.health.pa_temperature; comma();
			query_str += p.payload.health.reboot_count; comma();
			query_str += p.payload.health.data_packets_pending; comma();
			query_str += p.payload.health.antenna_switch; comma();
			query_str += p.payload.health.rx_noisefloor; comma();
			query_str += p.payload.health.detected_flash_errors; comma();
			query_str += p.payload.health.detected_ram_errors; comma();
			query_str += p.payload.health.battery_voltage; comma();
			query_str += p.payload.health.battery_current; comma();
			query_str += p.payload.health.battery_temperature; comma();
			query_str += p.payload.health.charge_current; comma();
			query_str += p.payload.health.mppt_voltage; comma();
			query_str += p.payload.health.solar_n1_current; comma();
			query_str += p.payload.health.solar_n2_current; comma();
			query_str += p.payload.health.solar_e1_current; comma();
			query_str += p.payload.health.solar_e2_current; comma();
			query_str += p.payload.health.solar_s1_current; comma();
			query_str += p.payload.health.solar_s2_current; comma();
			query_str += p.payload.health.solar_w1_current; comma();
			query_str += p.payload.health.solar_w2_current; comma();
			query_str += p.payload.health.solar_t1_current; comma();
			query_str += p.payload.health.solar_t2_current; comma();
			query_str += p.payload.health.rails_switch_status[0]; comma();
			query_str += p.payload.health.rails_switch_status[1]; comma();
			query_str += p.payload.health.rails_switch_status[2]; comma();
			query_str += p.payload.health.rails_switch_status[3]; comma();
			query_str += p.payload.health.rails_switch_status[4]; comma();
			query_str += p.payload.health.rails_switch_status[5]; comma();
			query_str += p.payload.health.rails_overcurrent_status[0]; comma();
			query_str += p.payload.health.rails_overcurrent_status[1]; comma();
			query_str += p.payload.health.rails_overcurrent_status[2]; comma();
			query_str += p.payload.health.rails_overcurrent_status[3]; comma();
			query_str += p.payload.health.rails_overcurrent_status[4]; comma();
			query_str += p.payload.health.rails_overcurrent_status[5]; comma();
			query_str += p.payload.health.rail_1_boot_count; comma();
			query_str += p.payload.health.rail_1_overcurrent_count; comma();
			query_str += p.payload.health.rail_1_voltage; comma();
			query_str += p.payload.health.rail_1_current; comma();
			query_str += p.payload.health.rail_2_boot_count; comma();
			query_str += p.payload.health.rail_2_overcurrent_count; comma();
			query_str += p.payload.health.rail_2_voltage; comma();
			query_str += p.payload.health.rail_2_current; comma();
			query_str += p.payload.health.rail_3_boot_count; comma();
			query_str += p.payload.health.rail_3_overcurrent_count; comma();
			query_str += p.payload.health.rail_3_voltage; comma();
			query_str += p.payload.health.rail_3_current; comma();
			query_str += p.payload.health.rail_4_boot_count; comma();
			query_str += p.payload.health.rail_4_overcurrent_count; comma();
			query_str += p.payload.health.rail_4_voltage; comma();
			query_str += p.payload.health.rail_4_current; comma();
			query_str += p.payload.health.rail_5_boot_count; comma();
			query_str += p.payload.health.rail_5_overcurrent_count; comma();
			query_str += p.payload.health.rail_5_voltage; comma();
			query_str += p.payload.health.rail_5_current; comma();
			query_str += p.payload.health.rail_6_boot_count; comma();
			query_str += p.payload.health.rail_6_overcurrent_count; comma();
			query_str += p.payload.health.rail_6_voltage; comma();
			query_str += p.payload.health.rail_6_current; comma();
			query_str += p.payload.health._3v3_voltage; comma();
			query_str += p.payload.health._3v3_current; comma();
			query_str += p.payload.health._5v_voltage; comma();
			query_str += p.payload.health._5v_current;
			query_str += ");\n";
			break;
		case PayloadType::Img :
			query_str += "INSERT INTO IMG (packID, seqPayload, payloadTimeStamp, \
					imgID, fragID, fragNums, imgData) VALUES ("
			query_str += "last_insert_id(), ";
			query_str += p.payload.img.sequence_id; comma();
			query_str += p.payload.img.timestamp; comma();
			query_str += p.payload.img.image_id; comma();
			query_str += p.payload.img.fragment_id; comma();
			query_str += p.payload.img.num_fragments; comma();
			query_str += p.payload.img.image_data;
			query_str += ");\n";
			break;
		case PayloadType::Config :
			// TODO @bug: Conf needs finishing
			break;
	}

	query_str += "COMMIT;";
	return query.exec(query_str);
}
