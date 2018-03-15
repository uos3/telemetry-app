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
		// TODO - can prob deal with this better.
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
// TODO - necessary?
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

	// packet
	query_str += "insert into packets (packCHK, packHASH, seqStat, seqPayload,"
	    "payloadType, downlinkTime) values (";
	query_str += p.hash + ", ";
	query_str += p.crc + ", ";
	query_str += p.status.sequence_id + ", ";
//	query_str += p.payload.xxx.sequence_id + ", "; // TODO @finish: get correct payload
	query_str += p.type + ")\n";

	// status
	query_str += "insert into status (packID, seqStat, SCID, SCTime,"
	    "timeSource, OBCTemp, battTemp, battVolt, battCurrent, chargeCurrent,"
	    "antDep, dataPending, rebootCnt, rails1, rails2, rails3, rails4,"
	    "rails5, rails6, RXTemp, TXTemp, PATemp, RXNoiseFloor) values (";
	query_str += "last_insert_id(), ";
	query_str += p.status.sequence_id + ", ";
	query_str += p.status.spacecraft_id + ", ";
	query_str += p.status.time + ", ";
	query_str += p.status.time_source + ", ";
	query_str += p.status.obc_temperature + ", ";
	query_str += p.status.battery_temperature + ", ";
	query_str += p.status.battery_voltage + ", ";
	query_str += p.status.battery_current + ", ";
	query_str += p.status.charge_current + ", ";
	query_str += p.status.antenna_deployment + ", ";
	query_str += p.status.data_pending + ", ";
	query_str += p.status.reboot_count + ", ";
	query_str += p.status.rails_status[0] + ", ";
	query_str += p.status.rails_status[1] + ", ";
	query_str += p.status.rails_status[2] + ", ";
	query_str += p.status.rails_status[3] + ", ";
	query_str += p.status.rails_status[4] + ", ";
	query_str += p.status.rails_status[5] + ", ";
	query_str += p.status.rx_temperature + ", ";
	query_str += p.status.tx_temperature + ", ";
	query_str += p.status.pa_temperature + ", ";
	query_str += p.status.rx_noisefloor + ")";

	// payload
//	query_str += "payload";
	// TODO @finish: get the right type of payload, fill out all the values.

	query_str += "COMMIT;";
	return query.exec(query_str);
}