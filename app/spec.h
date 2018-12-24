#include "buffer.h"

#include <QJsonObject>

QJsonObject spec_from_file (const std::string& filename);

QString spec_name (const QJsonObject& spec, const std::string& type, const std::string& default_name);

QVariant get_variant (Buffer& b);

QVariant field_value (const QJsonObject& field_spec, Buffer& b);

std::map<std::string, QVariant> map_from_buffer (Buffer& b, int starting_pos, const std::string& spec_filename);
