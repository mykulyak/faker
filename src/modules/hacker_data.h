#ifndef FAKER_MODULES_HACKER_DATA_H
#define FAKER_MODULES_HACKER_DATA_H

#include <array>
#include <string_view>

namespace faker::hacker::data {
extern const std::array<std::string_view, 16> abbreviations;
extern const std::array<std::string_view, 16> adjectives;
extern const std::array<std::string_view, 16> ingverbs;
extern const std::array<std::string_view, 16> nouns;
extern const std::array<std::string_view, 8> phrases;
extern const std::array<std::string_view, 16> verbs;
}

#endif