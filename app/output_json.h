#pragma once

#include "output.h"

#include <cereal/archives/json.hpp>

#include <iostream>


// for outputting parsed packets as json to the given output stream.
class JsonOutput : public Output
{
	Q_OBJECT

public:
	JsonOutput (std::ostream& os=std::cout, QObject* parent=nullptr);

protected:
	bool do_output (const Buffer& buffer, const Packet& packet) override;

private:
	cereal::JSONOutputArchive archive;
};
