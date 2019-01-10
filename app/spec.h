#include "buffer.h"

#include <QJsonDocument>
#include <QJsonObject>

QJsonObject spec_from_file (const std::string& filename);

QString spec_name (const QJsonObject& spec, const std::string& type, const std::string& default_name);

QVariant get_variant (Buffer& b);

QVariant field_value (const QJsonObject& field_spec, Buffer& b);

QMap<QString, QVariant> map_from_buffer (Buffer& b, int starting_pos, const std::string& spec_filename);

QMap<QString, QVariant> parse_packet (Buffer& b);

/* TODO #remove */
/* QJsonDocument map_to_json (std::map<std::string, QVariant> mymap); */
