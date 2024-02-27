#include "../common/random.h"
#include "database_data.h"
#include <faker/database.h>
#include <faker/string.h>

namespace faker::database {
std::string_view column_name() { return random::element(data::columnNames); }

std::string_view column_type() { return random::element(data::columnTypes); }

std::string_view collation() { return random::element(data::collations); }

std::string_view engine() { return random::element(data::engines); }

std::string mongodb_object_id()
{
    return string::hexadecimal(24, HexCasing::Lower, HexPrefix::None);
}
}
