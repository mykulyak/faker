#ifndef FAKER_TESTING_JSON_HELPER_H
#define FAKER_TESTING_JSON_HELPER_H

#include <string>
#include <unordered_map>

namespace faker::testing {
// this function parse simple JSON like {"key1":"value1","key2":"value2"}
std::unordered_map<std::string, std::string> simple_json_parser(std::string json_str);
}

#endif
