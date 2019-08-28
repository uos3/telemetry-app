#include "statusbar.h"
using namespace StatusBar;


namespace {
QStatusBar* instance = nullptr;

QtMessageHandler defaultMessageHandler = nullptr;
}

QStatusBar* StatusBar::get_instance() { return instance; }

void StatusBar::set_instance(QStatusBar* value) { instance = value; }

void StatusBar::message_handler (
	QtMsgType type, const QMessageLogContext &context, const QString &msg) {

	// style the message in the statusbar.
	if (instance != nullptr) {
		switch (type) {
		case QtDebugMsg:
			instance->setStyleSheet(DEBUG_STYLESHEET);
			break;
		case QtInfoMsg:
			instance->setStyleSheet(INFO_STYLESHEET);
			break;
		case QtWarningMsg:
			instance->setStyleSheet(WARNING_STYLESHEET);
			break;
		case QtCriticalMsg:
			instance->setStyleSheet(CRITICAL_STYLESHEET);
			break;
		default:
			instance->setStyleSheet(DEFAULT_STYLESHEET);
			break;
		}

		instance->showMessage(msg, MESSAGE_DURATION_MS);
	}

	// call the default handler (log to console).
	if (defaultMessageHandler != nullptr)
		(*defaultMessageHandler)(type, context, msg);
}

void StatusBar::install_message_handler () {
	defaultMessageHandler = qInstallMessageHandler(0);
	qInstallMessageHandler(message_handler);
}
