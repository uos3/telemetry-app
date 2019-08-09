#pragma once

#include <QAbstractListModel>
#include <QModelIndex>
#include <QSqlQueryModel>
#include <QVariant>


class DBColumns : public QAbstractListModel {
	Q_OBJECT

public:
	explicit DBColumns (std::string name,
	                    const QSqlQueryModel& model,
	                    QObject* parent=nullptr);

	bool is_checked (std::string name) const;

	// qabstractitemmodel overrides
	int rowCount (const QModelIndex& parent=QModelIndex()) const override;

	QVariant data (const QModelIndex& index, int role=Qt::DisplayRole) const override;

	bool setData (const QModelIndex& index,
	              const QVariant& value,
	              int role=Qt::EditRole) override;

	Qt::ItemFlags flags (const QModelIndex& index) const override;

	// getters
	std::string get_name () const;

	std::vector<std::string> get_column_names () const;

signals:
	void column_toggled (std::string column);

private:
	std::string name;

	// kind of odd not just having a map, but we need vectors so that we can keep our
	// secific ordering of keys (column names) and index into them by integer index (as
	// is needed to implement DBColumns::data).
	std::vector<std::string> column_names;
	std::vector<bool> columns_enabled;
};
