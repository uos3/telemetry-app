#include "uploader_settings.h"

#include <QFormLayout>
#include <QIntValidator>


UploaderSettings::UploaderSettings (Uploader& uploader,
                                    QWidget* parent,
                                    Qt::WindowFlags f)
                                   : QDialog(parent, f)
                                   , uploader(uploader)
                                   , address_field(new QLineEdit(this))
                                   , port_field(new QLineEdit(this))
                                   , app_key_field(new QLineEdit(this))
                                   , submit_key_field(new QLineEdit(this))
                                   , buttons(new QDialogButtonBox(
                                       QDialogButtonBox::Cancel |
                                       QDialogButtonBox::Save,
                                       this)) {
	// configure the window.
	setMinimumWidth(MINIMUM_WIDTH);

	QFormLayout* layout = new QFormLayout(this);
	setLayout(layout);
	layout->setContentsMargins(MARGINS, MARGINS, MARGINS, MARGINS);
	layout->setLabelAlignment(Qt::AlignRight);

	layout->addRow("Address:", address_field);
	layout->addRow("Port:", port_field);
	layout->addRow("App key:", app_key_field);
	layout->addRow("Submit key:", submit_key_field);
	layout->addWidget(buttons);

	// configure the fields.
	port_field->setValidator(new QIntValidator(0, 65535, port_field));

	// connect up the buttons to save or cancel.
	connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void UploaderSettings::accept () {
	if (!address_field->hasAcceptableInput() ||
	    !port_field->hasAcceptableInput() ||
	    !app_key_field->hasAcceptableInput() ||
	    !submit_key_field->hasAcceptableInput()) {
		return; // TODO feedback to the user.
	}

	bool ok;
	// validator should make sure that the value fits in the range of a uint16_t
	uint16_t port = static_cast<uint16_t>(port_field->text().toULong(&ok));
	if (!ok) return;

	uploader.set_address(address_field->text().toStdString());
	uploader.set_port(port);
	uploader.set_app_key(app_key_field->text().toStdString());
	uploader.set_submit_key(submit_key_field->text().toStdString());
	done(1);
}

void UploaderSettings::showEvent (QShowEvent* event) {
	Q_UNUSED(event);

	// when the window's shown, reset the fields to equal the current uploader config.
	address_field->setText(QString::fromStdString(uploader.get_address()));
	port_field->setText(QString::number(uploader.get_port()));
	app_key_field->setText(QString::fromStdString(uploader.get_app_key()));
	submit_key_field->setText(QString::fromStdString(uploader.get_submit_key()));
}
