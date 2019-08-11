#include "db_columns.h"


DBColumns::DBColumns (std::string table_name, const QSqlQueryModel& model, QObject* parent)
          : QAbstractListModel(parent)
          , table_name(table_name) {
	// insert names and checkedness (default off) for each column in the table
	for (int i = 0; i < model.columnCount(); i++) {
		column_names.push_back(
			model.headerData(i, Qt::Horizontal).toString().toStdString());
		columns_enabled.push_back(false);
	}
}

bool DBColumns::is_checked (std::string name) const {
	auto it = std::find(column_names.begin(), column_names.end(), name);

	if (it != column_names.end())
		return columns_enabled[std::distance(column_names.begin(), it)];

	return false;
}

int DBColumns::rowCount (const QModelIndex& parent) const {
	Q_UNUSED(parent);

	return static_cast<int>(column_names.size());
}

QVariant DBColumns::data (const QModelIndex& index, int role) const {
	// invalid cases
	if (!index.isValid())
		return QVariant();

	int idx = index.row();

	if (idx < 0 || idx > rowCount())
		return QVariant();

	// valid cases
	if (role == Qt::DisplayRole)
		return QString::fromStdString(column_names[idx]);

	if (role == Qt::CheckStateRole)
		return columns_enabled[idx] ? Qt::Checked : Qt::Unchecked;

	// not allowed role
	return QVariant();
}

bool DBColumns::setData (const QModelIndex& index, const QVariant& value, int role) {
	if (!index.isValid())
		return false;

	// handle (un)checking
	if (role == Qt::CheckStateRole) {
		columns_enabled[index.row()] = value.toInt() == Qt::Checked;
		emit column_toggled(column_names[index.row()]);
		return true;
	}

	return false;
}

Qt::ItemFlags DBColumns::flags (const QModelIndex& index) const {
	Q_UNUSED(index);

	// only allow (un)checking
	return Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
}

std::string DBColumns::get_table_name () const {
	return table_name;
}

std::vector<std::string> DBColumns::get_column_names () const {
	return column_names;
}
