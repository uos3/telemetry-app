#include "output_json.h"

#include <iostream>


JsonOutput::JsonOutput (std::ostream& os, QObject* parent)
	: Output(parent)
	, archive(os) {}

void JsonOutput::output (const Buffer& buffer, const Packet& packet) {
	Q_UNUSED(buffer);

	archive(CEREAL_NVP(packet));
}
