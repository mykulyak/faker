#include "json_helper.h"
#include <sstream>

namespace faker::testing {

std::unordered_map<std::string, std::string> simple_json_parser(std::string json_str)
{
    std::unordered_map<std::string, std::string> result;
    std::istringstream stream(json_str);
    std::string key, value, temp;
    char ch;

    while (stream >> ch && ch != '}') {
        if (ch == '"') {
            std::getline(stream, key, '"');
            std::getline(stream, temp, ':');

            stream >> ch;
            std::getline(stream, value, '"');

            result[key] = value;
        }
    }

    return result;
}
}
