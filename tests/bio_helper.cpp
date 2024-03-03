#include "bio_helper.h"
#include <faker/internet.h>
#include <modules/person_data.h>
#include <modules/word_data.h>
#include <regex>
#include <vector>

namespace faker::testing {

namespace {

    template <typename ContainerT>
    bool find_bio_part(const ContainerT& cont, std::smatch::const_reference match)
    {
        std::string_view match_view(&*match.first, match.length());
        return std::find(cont.begin(), cont.end(), match_view) != cont.end();
    }

}

bool check_bio_format(const std::string& bio)
{
    const std::regex re_format_1 { R"(^(\w+\s?\w+)$)" };
    const std::regex re_format_2 { R"(^(\w+\s?\w+), (\w+\s?\w+)$)" };
    const std::regex re_format_3 { R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+)$)" };
    const std::regex re_format_4 { R"(^(\w+\s?\w+), (\w+\s?\w+), (\w+\s?\w+), (\S+)$)" };
    const std::regex re_format_5 { R"(^(\w+\-?\w+) (\w+)$)" };
    const std::regex re_format_6 { R"(^(\w+\-?\w+) (\w+) (\S+)$)" };
    const std::regex re_format_7 { R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+)$)" };
    const std::regex re_format_8 { R"(^(\w+\-?\w+) (\w+), (\w+\s?\w+) (\S+)$)" };

    std::smatch matches;

    if (std::regex_match(std::begin(bio), std::end(bio), matches, re_format_1)) {
        // In this case the bio is in the format {bio_part} so check that the value is present in
        // the bio_part vector.
        if (find_bio_part(person::data::bio_parts, matches[0])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, re_format_2)) {
        // In this case the bio is in the format {bio_part}, {bio_part} so check that the value is
        // present in the bio_part vector.
        if (find_bio_part(person::data::bio_parts, matches[1])
            && find_bio_part(person::data::bio_parts, matches[2])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, re_format_3)) {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part} so check that
        // the value is present in the bio_part vector.
        if (find_bio_part(person::data::bio_parts, matches[1])
            && find_bio_part(person::data::bio_parts, matches[2])
            && find_bio_part(person::data::bio_parts, matches[3])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, re_format_4)) {
        // In this case the bio is in the format {bio_part}, {bio_part}, {bio_part}, {emoji} so
        // check that the value is present in the bio_part vector.
        if (find_bio_part(person::data::bio_parts, matches[1])
            && find_bio_part(person::data::bio_parts, matches[2])
            && find_bio_part(person::data::bio_parts, matches[3])
            && internet::is_valid_emoji(matches[4])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, re_format_5)) {
        // In this case the bio is in the format {noun} {bio_supporter} so check that the value is
        // present in the bio_part vector.
        if (find_bio_part(word::data::nouns, matches[1])
            && find_bio_part(person::data::bio_supporters, matches[2])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, re_format_6)) {
        // In this case the bio is in the format {noun} {bio_supporter} {emoji} so check that the
        // value is present in the bio_part vector.
        if (find_bio_part(word::data::nouns, matches[1])
            && find_bio_part(person::data::bio_supporters, matches[2])
            && internet::is_valid_emoji(matches[3])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, re_format_7)) {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} so check that
        // the value is present in the bio_part vector.
        if (find_bio_part(word::data::nouns, matches[1])
            && find_bio_part(person::data::bio_supporters, matches[2])
            && find_bio_part(person::data::bio_parts, matches[3])) {
            return true;
        }
    }

    if (std::regex_match(bio, matches, re_format_8)) {
        // In this case the bio is in the format {noun} {bio_supporter}, {bio_part} {emoji} so check
        // that the value is present in the bio_part vector.
        if (find_bio_part(word::data::nouns, matches[1])
            && find_bio_part(person::data::bio_supporters, matches[2])
            && find_bio_part(person::data::bio_parts, matches[3])
            && internet::is_valid_emoji(matches[4])) {
            return true;
        }
    }

    return false;
}
}
