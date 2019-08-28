#pragma once

#include <QMessageLogContext>
#include <QStatusBar>
#include <QString>


// this namespace contains a QStatusBar that once activated (with
// `install_message_handler`) will display the most recent message printed with
// `q(Debug|Warning|Critical)`, with appropriate style.
//
// example usage (from a window class):
//
// ```cpp
// StatusBar::set_instance(new QStatusBar(this));
// StatusBar::install_message_handler();
// setStatusBar(StatusBar::get_instance());
// ```
//
// it would be nice for this to be a subclass of QStatusBar. however, in order to
// install the message handler to get logging messages, you must supply a specific type
// of function pointer. since methods on a class also have an implicit `this` pointer
// passed into them, the signatures don't match and so `message_handler` must be a free
// function.
namespace StatusBar {
	const QString DEFAULT_STYLESHEET = "color: black";
	const QString DEBUG_STYLESHEET = "color: black";
	const QString INFO_STYLESHEET = "color: black";
	const QString WARNING_STYLESHEET = "color: #ad600d";
	const QString CRITICAL_STYLESHEET = "color: #ad100d";

	const int MESSAGE_DURATION_MS = 10000;

	QStatusBar* get_instance();

	void set_instance(QStatusBar* value);

	void message_handler (
		QtMsgType type, const QMessageLogContext &context, const QString &msg);

	void install_message_handler ();
}
