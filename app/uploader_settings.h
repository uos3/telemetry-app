#pragma once

#include "uploader.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QShowEvent>


class UploaderSettings : public QDialog {
	Q_OBJECT
public:
	explicit UploaderSettings (
		Uploader& uploader,
		QWidget* parent = nullptr,
		Qt::WindowFlags f = Qt::WindowFlags());

	void accept () override;

protected:
	void showEvent (QShowEvent* event) override;

private:
	static const int MARGINS = 10;
	static const int MINIMUM_WIDTH = 500;

	Uploader& uploader;

	QLineEdit* address_field;
	QLineEdit* port_field;
	QLineEdit* app_key_field;
	QLineEdit* submit_key_field;

	QDialogButtonBox* buttons;
};
