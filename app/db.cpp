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
	query_str += "INSERT INTO PACKETS (packCHK, packHASH, seqStat, seqPayload,"
	    "payloadType, downlinkTime) VALUES (";
	query_str += p.crc; comma();
	query_str += p.hash; comma();
	query_str += p.status.sequence_id; comma();
	switch (static_cast<int>(p.type)) {
		case 2 :
			query_str += p.payload.gps.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case 3 :
			query_str += p.payload.imu.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case 4 :
			query_str += p.payload.health.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case 5 :
			query_str += p.payload.img.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
		case 6 :
			query_str += p.payload.conf.sequence_id; comma();
			query_str += static_cast<int>(p.type); comma();
			break;
	}
	query_str += p.downlink_time;
	query_str += ");\n";

	// status
	query_str += "INSERT INTO STATUS (packID, seqStat, SCID, SCTime,"
	    "timeSource, OBCTemp, battTemp, battVolt, battCurrent, chargeCurrent,"
	    "antDep, dataPending, rebootCnt, rails1, rails2, rails3, rails4,"
	    "rails5, rails6, RXTemp, TXTemp, PATemp, RXNoiseFloor) VALUES (";
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
	switch (static_cast<int>(p.type)) {
		// TODO @finish: get the right type of payload, fill out all the values.
	}

	query_str += "COMMIT;";
	return query.exec(query_str);
}
