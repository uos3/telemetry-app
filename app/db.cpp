#include "db.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QTextStream>

#include <ctime>

DB::DB (std::string hostname, std::string dbname) :
dbname(dbname), hostname(hostname) {
// set up db
	// 'QMYSQL driver not loaded' -> https://stackoverflow.com/a/47334605
	// TODO #enhancement: would prob be better to use sqlite than mysql
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(QString::fromStdString(hostname));
	db.setDatabaseName(QString::fromStdString(dbname));
}

DB::DB(const DB& other) : dbname(other.dbname), hostname(other.hostname) {
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(QString::fromStdString(hostname));
	db.setDatabaseName(QString::fromStdString(dbname));
}

DB& DB::operator=(const DB& other) {
	if (db.isOpen()) { db.close(); }

	dbname = other.dbname;
	hostname = other.hostname;
	db.setHostName(QString::fromStdString(hostname));
	db.setDatabaseName(QString::fromStdString(dbname));

	return *this;
}

DB::~DB () {
	if (db.isOpen()) { db.close(); }
}

bool DB::connect (std::string username, std::string password) {
	return db.open(QString::fromStdString(username),
	               QString::fromStdString(password));
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

// TODO #enhancement: bind values properly -- allows for easily passing the
//                    binary.
//                    * turn the 'insert into ___ (...) values (...)' into a
//                      string with placeholder values.
//                    * call bindValue(":thing", thing) instead of adding to
//                      the stream.
//                    * hopefully you can call prepare after binding values?
//                      then it's easier to build up the different statements
//                      based on a condition.
//                      * eg. then you can switch to make the stream based on
//                        payload type, but can still call things like
//                        bindValue(":crc", p.crc) as you go.
//                    * would be a lot more natural to do this with
//                      transactions. are these guaranteed to be supported?
//bool DB::store_packet (Packet& p, QByteArray binary) {
//	QSqlQuery q;
//
//	db.transaction();
//
//	QString prep = "insert into test (string, number, bool, date, crc) "
//	               "values (:string, :number, :bool, :date, :crc);";
//	q.prepare(prep);
//	q.bindValue(":string", "hello");
//	q.bindValue(":number", 5);
//	q.bindValue(":bool", false);
//	q.bindValue(":date", "2018-10-28 21:12:45");
//	q.bindValue(":crc", "ab");
//	bool success = q.exec();
//
//	int id = q.lastInsertId().toInt();
//	qDebug() << "last insert id: " << id;
//
//	char str[2]; // note: (intentionally) not null-terminated.
//	str[0] = 'o';
//	str[1] = 'k';
//
//	q.prepare(prep);
//	q.bindValue(":string", str);
//	q.bindValue(":number", id);
//	q.bindValue(":bool", true);
//	q.bindValue(":date", "2018-10-28 21:12:45");
//	q.bindValue(":crc", str);
//	success &= q.exec();
//
//	db.commit();
//
//	qDebug() << q.executedQuery();
//	if (q.lastError().isValid()) {
//		qCritical() << "error storing packet in local database:" << q.lastError().text();
//	}
//
//	if (success) {
//		qDebug() << "database query sent successfully.";
//		return true;
//	} else {
//		qCritical() << "failed to send query to store packet in local database.";
//		return false;
//	}
//}

bool DB::store_packet (Packet& p, QByteArray binary) {
	QSqlQuery query;

	db.transaction();

	// frame
	QString qstr = "insert into frames (frame_bin, frame_chksum, frame_hash, "
	               "seq_status, seq_payload, payload_type, downlink_time) "
	               "values (:frame_bin, :frame_chksum, :frame_hash, "
	               ":seq_status, :seq_payload, :payload_type, "
	               ":downlink_time);";
	if (!query.prepare(qstr)) { qCritical() << "Error preparing query for frame table."; }
	query.bindValue(":frame_bin", binary, QSql::In | QSql::Binary);
	query.bindValue(":frame_chksum", p.crc);
	query.bindValue(":frame_hash", p.hash);
	query.bindValue(":seq_status", p.status.sequence_id);
	switch (p.type) {
		case PayloadType::GPS:
			query.bindValue(":seq_payload", p.payload.gps.sequence_id);
			query.bindValue(":payload_type", "gps");
			break;
		case PayloadType::IMU:
			query.bindValue(":seq_payload", p.payload.imu.sequence_id);
			query.bindValue(":payload_type", "imu");
			break;
		case PayloadType::Health:
			query.bindValue(":seq_payload", p.payload.health.sequence_id);
			query.bindValue(":payload_type", "health");
			break;
		case PayloadType::Img:
			query.bindValue(":seq_payload", p.payload.img.sequence_id);
			query.bindValue(":payload_type", "img");
			break;
		case PayloadType::Config:
			query.bindValue(":seq_payload", p.payload.config.sequence_id);
			query.bindValue(":payload_type", "config");
			break;
		default:
			qCritical() << "payload type not supported!";
			return false;
	}
	query.bindValue(":downlink_time", time_string(p.downlink_time));

	bool success = query.exec();
	if (!success) { qCritical() << "error inserting frame!: " << query.lastError().text(); }

	int frame_id = query.lastInsertId().toInt();

	// status
	qstr = "insert into status (frame_id, spacecraft_id, spacecraft_time, "
	       "time_source, seq_status, obc_temperature, battery_temperature, "
	       "battery_voltage, battery_current, charge_current, "
	       "antenna_deployment, data_pending, reboot_count, rails_1, "
	       "rails_2, rails_3, rails_4, rails_5, rails_6, rx_temperature, "
	       "tx_temperature, pa_temperature, rx_noisefloor) values (:frame_id, "
	       ":spacecraft_id, :spacecraft_time, :time_source, :seq_status, "
	       ":obc_temperature, :battery_temperature, :battery_voltage, "
	       ":battery_current, :charge_current, :antenna_deployment, "
	       ":data_pending, :reboot_count, :rails_1, :rails_2, :rails_3, "
	       ":rails_4, :rails_5, :rails_6, :rx_temperature, :tx_temperature, "
	       ":pa_temperature, :rx_noisefloor);";
	if (!query.prepare(qstr)) { qCritical() << "Error preparing query for status table."; }
	query.bindValue(":frame_id", frame_id);
	query.bindValue(":spacecraft_id", p.status.spacecraft_id);
	query.bindValue(":spacecraft_time", time_string(p.status.time));
	query.bindValue(":time_source", p.status.time_source);
	query.bindValue(":seq_status", p.status.sequence_id);
	query.bindValue(":obc_temperature", p.status.obc_temperature);
	query.bindValue(":battery_temperature", p.status.battery_temperature);
	query.bindValue(":battery_voltage", p.status.battery_voltage);
	query.bindValue(":battery_current", p.status.battery_current);
	query.bindValue(":charge_current", p.status.charge_current);
	query.bindValue(":antenna_deployment", p.status.antenna_deployment);
	query.bindValue(":data_pending", p.status.data_pending);
	query.bindValue(":reboot_count", p.status.reboot_count);
	query.bindValue(":rails_1", p.status.rails_status[0]);
	query.bindValue(":rails_2", p.status.rails_status[1]);
	query.bindValue(":rails_3", p.status.rails_status[2]);
	query.bindValue(":rails_4", p.status.rails_status[3]);
	query.bindValue(":rails_5", p.status.rails_status[4]);
	query.bindValue(":rails_6", p.status.rails_status[5]);
	query.bindValue(":rx_temperature", p.status.rx_temperature);
	query.bindValue(":tx_temperature", p.status.tx_temperature);
	query.bindValue(":pa_temperature", p.status.pa_temperature);
	query.bindValue(":rx_noisefloor", p.status.rx_noisefloor);

	success &= query.exec();
	if (!success) { qCritical() << "error inserting status!: " << query.lastError().text(); }

	// payload
	switch (p.type) {
		case PayloadType::GPS:
			qstr = "insert into gps (frame_id, seq_payload, "
			       "payload_timestamp, lat, lon, alt, hdop, vdop, pdop, "
			       "tdop) values (:frame_id, :seq_payload, "
			       ":payload_timestamp, :lat, :lon, :alt, :hdop, :vdop, :pdop, "
			       ":tdop);";
			if (!query.prepare(qstr)) {
				qCritical() << "Error preparing query for gps table:" << query.lastError().text();
			}
			query.bindValue(":frame_id", frame_id);
			query.bindValue(":seq_payload", p.payload.gps.sequence_id);
			query.bindValue(":payload_timestamp", time_string(p.payload.gps.timestamp));
			query.bindValue(":lat", p.payload.gps.lat);
			query.bindValue(":lon", p.payload.gps.lon);
			query.bindValue(":alt", p.payload.gps.alt);
			query.bindValue(":hdop", p.payload.gps.hdop);
			query.bindValue(":vdop", p.payload.gps.vdop);
			query.bindValue(":pdop", p.payload.gps.pdop);
			query.bindValue(":tdop", p.payload.gps.tdop);

			success &= query.exec();
			if (!success) { qCritical() << "error inserting gps!: " << query.lastError().text(); }

			break;

		case PayloadType::IMU:
			qstr = "insert into imu (frame_id, seq_payload, "
			       "payload_timestamp, mag_x_1, mag_x_2, mag_x_3, mag_x_4, "
			       "mag_x_5, mag_y_1, mag_y_2, mag_y_3, mag_y_4, mag_y_5, "
			       "mag_z_1, mag_z_2, mag_z_3, mag_z_4, mag_z_5, gyro_x_1, "
			       "gyro_x_2, gyro_x_3, gyro_x_4, gyro_x_5, gyro_y_1, gyro_y_2, "
			       "gyro_y_3, gyro_y_4, gyro_y_5, gyro_z_1, gyro_z_2, gyro_z_3, "
			       "gyro_z_4, gyro_z_5, accel_x_1, accel_x_2, accel_x_3, "
			       "accel_x_4, accel_x_5, accel_y_1, accel_y_2, accel_y_3, "
			       "accel_y_4, accel_y_5, accel_z_1, accel_z_2, accel_z_3, "
			       "accel_z_4, accel_z_5) values (:frame_id, :seq_payload, "
			       ":payload_timestamp, :mag_x_1, :mag_x_2, :mag_x_3, "
			       ":mag_x_4, :mag_x_5, :mag_y_1, :mag_y_2, :mag_y_3, "
			       ":mag_y_4, :mag_y_5, :mag_z_1, :mag_z_2, :mag_z_3, "
			       ":mag_z_4, :mag_z_5, :gyro_x_1, :gyro_x_2, :gyro_x_3, "
			       ":gyro_x_4, :gyro_x_5, :gyro_y_1, :gyro_y_2, :gyro_y_3, "
			       ":gyro_y_4, :gyro_y_5, :gyro_z_1, :gyro_z_2, :gyro_z_3, "
			       ":gyro_z_4, :gyro_z_5, :accel_x_1, :accel_x_2, :accel_x_3, "
			       ":accel_x_4, :accel_x_5, :accel_y_1, :accel_y_2, "
			       ":accel_y_3, :accel_y_4, :accel_y_5, :accel_z_1, "
			       ":accel_z_2, :accel_z_3, :accel_z_4, :accel_z_5);";
			if (!query.prepare(qstr)) {
				qCritical() << "Error preparing query for imu table:" << query.lastError().text();
			}
			query.bindValue(":frame_id", frame_id);
			query.bindValue(":seq_payload", p.payload.imu.sequence_id);
			query.bindValue(":payload_timestamp", time_string(p.payload.imu.timestamp));
			query.bindValue(":mag_x_1", p.payload.imu.mag_x[0]);
			query.bindValue(":mag_x_2", p.payload.imu.mag_x[1]);
			query.bindValue(":mag_x_3", p.payload.imu.mag_x[2]);
			query.bindValue(":mag_x_4", p.payload.imu.mag_x[3]);
			query.bindValue(":mag_x_5", p.payload.imu.mag_x[4]);
			query.bindValue(":mag_y_1", p.payload.imu.mag_y[0]);
			query.bindValue(":mag_y_2", p.payload.imu.mag_y[1]);
			query.bindValue(":mag_y_3", p.payload.imu.mag_y[2]);
			query.bindValue(":mag_y_4", p.payload.imu.mag_y[3]);
			query.bindValue(":mag_y_5", p.payload.imu.mag_y[4]);
			query.bindValue(":mag_z_1", p.payload.imu.mag_z[0]);
			query.bindValue(":mag_z_2", p.payload.imu.mag_z[1]);
			query.bindValue(":mag_z_3", p.payload.imu.mag_z[2]);
			query.bindValue(":mag_z_4", p.payload.imu.mag_z[3]);
			query.bindValue(":mag_z_5", p.payload.imu.mag_z[4]);
			query.bindValue(":gyro_x_1", p.payload.imu.gyro_x[0]);
			query.bindValue(":gyro_x_2", p.payload.imu.gyro_x[1]);
			query.bindValue(":gyro_x_3", p.payload.imu.gyro_x[2]);
			query.bindValue(":gyro_x_4", p.payload.imu.gyro_x[3]);
			query.bindValue(":gyro_x_5", p.payload.imu.gyro_x[4]);
			query.bindValue(":gyro_y_1", p.payload.imu.gyro_y[0]);
			query.bindValue(":gyro_y_2", p.payload.imu.gyro_y[1]);
			query.bindValue(":gyro_y_3", p.payload.imu.gyro_y[2]);
			query.bindValue(":gyro_y_4", p.payload.imu.gyro_y[3]);
			query.bindValue(":gyro_y_5", p.payload.imu.gyro_y[4]);
			query.bindValue(":gyro_z_1", p.payload.imu.gyro_z[0]);
			query.bindValue(":gyro_z_2", p.payload.imu.gyro_z[1]);
			query.bindValue(":gyro_z_3", p.payload.imu.gyro_z[2]);
			query.bindValue(":gyro_z_4", p.payload.imu.gyro_z[3]);
			query.bindValue(":gyro_z_5", p.payload.imu.gyro_z[4]);
			query.bindValue(":accel_x_1", p.payload.imu.accel_x[0]);
			query.bindValue(":accel_x_2", p.payload.imu.accel_x[1]);
			query.bindValue(":accel_x_3", p.payload.imu.accel_x[2]);
			query.bindValue(":accel_x_4", p.payload.imu.accel_x[3]);
			query.bindValue(":accel_x_5", p.payload.imu.accel_x[4]);
			query.bindValue(":accel_y_1", p.payload.imu.accel_y[0]);
			query.bindValue(":accel_y_2", p.payload.imu.accel_y[1]);
			query.bindValue(":accel_y_3", p.payload.imu.accel_y[2]);
			query.bindValue(":accel_y_4", p.payload.imu.accel_y[3]);
			query.bindValue(":accel_y_5", p.payload.imu.accel_y[4]);
			query.bindValue(":accel_z_1", p.payload.imu.accel_z[0]);
			query.bindValue(":accel_z_2", p.payload.imu.accel_z[1]);
			query.bindValue(":accel_z_3", p.payload.imu.accel_z[2]);
			query.bindValue(":accel_z_4", p.payload.imu.accel_z[3]);
			query.bindValue(":accel_z_5", p.payload.imu.accel_z[4]);

			success &= query.exec();
			if (!success) { qCritical() << "error inserting imu!: " << query.lastError().text(); }

			break;

		case PayloadType::Health:
			qstr =  "insert into health (frame_id, seq_payload, "
			        "payload_timestamp, obc_temperature, rx_temperature, "
			        "tx_temperature, pa_temperature, reboot_count, "
			        "data_packets_pending, antenna_switch, rx_noisefloor, "
			        "detected_flash_errors, detected_ram_errors, "
			        "battery_voltage, battery_current, battery_temperature, "
			        "charge_current, mppt_voltage, solar_n1_current, "
			        "solar_n2_current, solar_e1_current, solar_e2_current, "
			        "solar_s1_current, solar_s2_current, solar_w1_current, "
			        "solar_w2_current, solar_t1_current, solar_t2_current, "
			        "rails_switch_status_1, rails_switch_status_2, "
			        "rails_switch_status_3, rails_switch_status_4, "
			        "rails_switch_status_5, rails_switch_status_6, "
			        "rails_overcurrent_status_1, rails_overcurrent_status_2, "
			        "rails_overcurrent_status_3, rails_overcurrent_status_4, "
			        "rails_overcurrent_status_5, rails_overcurrent_status_6, "
			        "rail_1_boot_count, rail_1_overcurrent_count, "
			        "rail_1_voltage, rail_1_current, rail_2_boot_count, "
			        "rail_2_overcurrent_count, rail_2_voltage, "
			        "rail_2_current, rail_3_boot_count, "
			        "rail_3_overcurrent_count, rail_3_voltage, "
			        "rail_3_current, rail_4_boot_count, "
			        "rail_4_overcurrent_count, rail_4_voltage, "
			        "rail_4_current, rail_5_boot_count, "
			        "rail_5_overcurrent_count, rail_5_voltage, "
			        "rail_5_current, rail_6_boot_count, "
			        "rail_6_overcurrent_count, rail_6_voltage, "
			        "rail_6_current, 3v3_voltage, 3v3_current, 5v_voltage, "
			        "5v_current) values (:frame_id, :seq_payload, "
			        ":payload_timestamp, :obc_temperature, :rx_temperature, "
			        ":tx_temperature, :pa_temperature, :reboot_count, "
			        ":data_packets_pending, :antenna_switch, :rx_noisefloor, "
			        ":detected_flash_errors, :detected_ram_errors, "
			        ":battery_voltage, :battery_current, :battery_temperature, "
			        ":charge_current, :mppt_voltage, :solar_n1_current, "
			        ":solar_n2_current, :solar_e1_current, :solar_e2_current, "
			        ":solar_s1_current, :solar_s2_current, :solar_w1_current, "
			        ":solar_w2_current, :solar_t1_current, :solar_t2_current, "
			        ":rails_switch_status_1, :rails_switch_status_2, "
			        ":rails_switch_status_3, :rails_switch_status_4, "
			        ":rails_switch_status_5, :rails_switch_status_6, "
			        ":rails_overcurrent_status_1, :rails_overcurrent_status_2, "
			        ":rails_overcurrent_status_3, "
			        ":rails_overcurrent_status_4, "
			        ":rails_overcurrent_status_5, :rails_overcurrent_status_6, "
			        ":rail_1_boot_count, :rail_1_overcurrent_count, "
			        ":rail_1_voltage, :rail_1_current, :rail_2_boot_count, "
			        ":rail_2_overcurrent_count, :rail_2_voltage, "
			        ":rail_2_current, :rail_3_boot_count, "
			        ":rail_3_overcurrent_count, :rail_3_voltage, "
			        ":rail_3_current, :rail_4_boot_count, "
			        ":rail_4_overcurrent_count, :rail_4_voltage, "
			        ":rail_4_current, :rail_5_boot_count, "
			        ":rail_5_overcurrent_count, :rail_5_voltage, "
			        ":rail_5_current, :rail_6_boot_count, "
			        ":rail_6_overcurrent_count, :rail_6_voltage, "
			        ":rail_6_current, :3v3_voltage, :3v3_current, :5v_voltage, "
			        ":5v_current);";
			if (!query.prepare(qstr)) {
				qCritical() << "Error preparing query for health table:" << query.lastError().text();
			}
			query.bindValue(":frame_id", frame_id);
			query.bindValue(":seq_payload", p.payload.health.sequence_id);
			query.bindValue(":payload_timestamp", time_string(p.payload.health.timestamp));
			query.bindValue(":obc_temperature", p.payload.health.obc_temperature);
			query.bindValue(":rx_temperature", p.payload.health.rx_temperature);
			query.bindValue(":tx_temperature", p.payload.health.tx_temperature);
			query.bindValue(":pa_temperature", p.payload.health.pa_temperature);
			query.bindValue(":reboot_count", p.payload.health.reboot_count);
			query.bindValue(":data_packets_pending", p.payload.health.data_packets_pending);
			query.bindValue(":antenna_switch", p.payload.health.antenna_switch);
			query.bindValue(":rx_noisefloor", p.payload.health.rx_noisefloor);
			query.bindValue(":detected_flash_errors", p.payload.health.detected_flash_errors);
			query.bindValue(":detected_ram_errors", p.payload.health.detected_ram_errors);
			query.bindValue(":battery_voltage", p.payload.health.battery_voltage);
			query.bindValue(":battery_current", p.payload.health.battery_current);
			query.bindValue(":battery_temperature", p.payload.health.battery_temperature);
			query.bindValue(":charge_current", p.payload.health.charge_current);
			query.bindValue(":mppt_voltage", p.payload.health.mppt_voltage);
			query.bindValue(":solar_n1_current", p.payload.health.solar_n1_current);
			query.bindValue(":solar_n2_current", p.payload.health.solar_n2_current);
			query.bindValue(":solar_e1_current", p.payload.health.solar_e1_current);
			query.bindValue(":solar_e2_current", p.payload.health.solar_e2_current);
			query.bindValue(":solar_s1_current", p.payload.health.solar_s1_current);
			query.bindValue(":solar_s2_current", p.payload.health.solar_s2_current);
			query.bindValue(":solar_w1_current", p.payload.health.solar_w1_current);
			query.bindValue(":solar_w2_current", p.payload.health.solar_w2_current);
			query.bindValue(":solar_t1_current", p.payload.health.solar_t1_current);
			query.bindValue(":solar_t2_current", p.payload.health.solar_t2_current);
			query.bindValue(":rails_switch_status_1", p.payload.health.rails_switch_status[0]);
			query.bindValue(":rails_switch_status_2", p.payload.health.rails_switch_status[1]);
			query.bindValue(":rails_switch_status_3", p.payload.health.rails_switch_status[2]);
			query.bindValue(":rails_switch_status_4", p.payload.health.rails_switch_status[3]);
			query.bindValue(":rails_switch_status_5", p.payload.health.rails_switch_status[4]);
			query.bindValue(":rails_switch_status_6", p.payload.health.rails_switch_status[5]);
			query.bindValue(":rails_overcurrent_status_1", p.payload.health.rails_overcurrent_status[0]);
			query.bindValue(":rails_overcurrent_status_2", p.payload.health.rails_overcurrent_status[1]);
			query.bindValue(":rails_overcurrent_status_3", p.payload.health.rails_overcurrent_status[2]);
			query.bindValue(":rails_overcurrent_status_4", p.payload.health.rails_overcurrent_status[3]);
			query.bindValue(":rails_overcurrent_status_5", p.payload.health.rails_overcurrent_status[4]);
			query.bindValue(":rails_overcurrent_status_6", p.payload.health.rails_overcurrent_status[5]);
			query.bindValue(":rail_1_boot_count", p.payload.health.rail_1_boot_count);
			query.bindValue(":rail_1_overcurrent_count", p.payload.health.rail_1_overcurrent_count);
			query.bindValue(":rail_1_voltage", p.payload.health.rail_1_voltage);
			query.bindValue(":rail_1_current", p.payload.health.rail_1_current);
			query.bindValue(":rail_2_boot_count", p.payload.health.rail_2_boot_count);
			query.bindValue(":rail_2_overcurrent_count", p.payload.health.rail_2_overcurrent_count);
			query.bindValue(":rail_2_voltage", p.payload.health.rail_2_voltage);
			query.bindValue(":rail_2_current", p.payload.health.rail_2_current);
			query.bindValue(":rail_3_boot_count", p.payload.health.rail_3_boot_count);
			query.bindValue(":rail_3_overcurrent_count", p.payload.health.rail_3_overcurrent_count);
			query.bindValue(":rail_3_voltage", p.payload.health.rail_3_voltage);
			query.bindValue(":rail_3_current", p.payload.health.rail_3_current);
			query.bindValue(":rail_4_boot_count", p.payload.health.rail_4_boot_count);
			query.bindValue(":rail_4_overcurrent_count", p.payload.health.rail_4_overcurrent_count);
			query.bindValue(":rail_4_voltage", p.payload.health.rail_4_voltage);
			query.bindValue(":rail_4_current", p.payload.health.rail_4_current);
			query.bindValue(":rail_5_boot_count", p.payload.health.rail_5_boot_count);
			query.bindValue(":rail_5_overcurrent_count", p.payload.health.rail_5_overcurrent_count);
			query.bindValue(":rail_5_voltage", p.payload.health.rail_5_voltage);
			query.bindValue(":rail_5_current", p.payload.health.rail_5_current);
			query.bindValue(":rail_6_boot_count", p.payload.health.rail_6_boot_count);
			query.bindValue(":rail_6_overcurrent_count", p.payload.health.rail_6_overcurrent_count);
			query.bindValue(":rail_6_voltage", p.payload.health.rail_6_voltage);
			query.bindValue(":rail_6_current", p.payload.health.rail_6_current);
			query.bindValue(":3v3_voltage", p.payload.health._3v3_voltage);
			query.bindValue(":3v3_current", p.payload.health._3v3_current);
			query.bindValue(":5v_voltage", p.payload.health._5v_voltage);
			query.bindValue(":5v_current", p.payload.health._5v_current);

			success &= query.exec();
			if (!success) { qCritical() << "error inserting health!: " << query.lastError().text(); }

			break;

		case PayloadType::Img:
			qstr = "insert into img (frame_id, seq_payload, "
			       "payload_timestamp, image_id, fragment_id, "
			       "num_fragments) values (:frame_id, :seq_payload,"
			       ":payload_timestamp, :image_id, :fragment_id,"
			       ":num_fragments);";
			if (!query.prepare(qstr)) {
				qCritical() << "Error preparing query for img table:" << query.lastError().text();
			}
			query.bindValue(":frame_id", frame_id);
			query.bindValue(":seq_payload", p.payload.img.sequence_id);
			query.bindValue(":payload_timestamp", time_string(p.payload.img.timestamp));
			query.bindValue(":image_id", p.payload.img.image_id);
			query.bindValue(":fragment_id", p.payload.img.fragment_id);
			query.bindValue(":num_fragments", p.payload.img.num_fragments);
			/* TODO #finish: upload image data (once I know the size). */
			/* query.bindValue(":image_data", p.payload.img.image_data); */

			success &= query.exec();
			if (!success) { qCritical() << "error inserting img!: " << query.lastError().text(); }

			break;

		case PayloadType::Config:
			// TODO #finish
			break;

		default:
			qCritical() << "payload type not supported!";
		    return false;
	}

	success &= db.commit();

	// TODO #refactor: remove prints (except maybe executedQuery & lastError)
	if (success) {
		qDebug() << "query to store packet in local database sent successfully.";
		return true;
	} else {
		qCritical() << "failed to send query to store packet in local database.";
		return false;
	}
}

QString DB::time_string (uint32_t tstamp) {
	time_t t = static_cast<time_t>(tstamp);
	tm* st = gmtime(&t);
	char s[22];
	strftime(s, 22, "%F %T", st);
	return QString(s);
}

std::string DB::get_name () { return this->dbname; }
std::string DB::get_hostname () { return this->hostname; }
