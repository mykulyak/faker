#include "../test_helpers.h"
#include <algorithm>
#include <faker/string.h>
#include <iostream>
#include <modules/string_data.h>
#include <random>
#include <stdexcept>
#include <unordered_set>
#include <vector>

using namespace faker;

namespace {

constexpr unsigned run_count = 100;

template <typename StringLikeT> inline bool is_valid_sample_str(const StringLikeT& str)
{
    return std::all_of(str.begin(), str.end(), [](char ch) {
        int ich = static_cast<int>(ch);
        return ich >= 33 && ich <= 125;
    });
}

template <typename StringLike1T, typename StringLike2T>
inline bool contains_only_chars_from(const StringLike1T& sample, const StringLike2T& allowed)
{
    return std::all_of(
        sample.begin(), sample.end(), [=](char c) { return allowed.find(c) != std::string::npos; });
}

}

TEST(StringTest, should_generate_uuid4)
{
    const auto uuid = string::uuid();

    EXPECT_EQ(uuid[8], '-');
    EXPECT_EQ(uuid[13], '-');
    EXPECT_EQ(uuid[14], '4');
    EXPECT_EQ(uuid[18], '-');
    EXPECT_EQ(uuid[23], '-');
}

TEST(StringTest, should_generate_sample_string)
{
    const auto sample_string_default_len = string::sample();
    const auto sample_string_custom_len = string::sample(5);

    EXPECT_EQ(sample_string_default_len.size(), 10u);
    EXPECT_TRUE(is_valid_sample_str(sample_string_default_len));

    EXPECT_EQ(sample_string_custom_len.size(), 5u);
    EXPECT_TRUE(is_valid_sample_str(sample_string_custom_len));
}

TEST(StringTest, should_generate_sample_string_with_guarantee_1)
{
    // atleast 1 ';' - 3 ',' - 2 'a'
    // atmost 3 ';' - 4 ',' - 10 'a'
    const std::vector<string::Spec> specs { { ';', 1, 3 }, { ',', 3, 4 }, { 'a', 2, 10 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sample = string::sample(specs, 20);

        EXPECT_EQ(sample.size(), 20u);
        EXPECT_TRUE(is_valid_sample_str(sample));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, ';'), 1u, 3u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, ','), 3u, 4u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'a'), 2u, 10u);
    }
}

TEST(StringTest, should_generate_sample_string_with_guarantee_2)
{
    // exactly 2 '@'
    // atmost 1 '4' - 2 '5' - 3 'a'
    const std::vector<string::Spec> specs { { '4', 0, 1 }, { '5', 0, 2 }, { 'a', 0, 3 },
        { '@', 2, 2 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sample = string::sample(specs, 20u);

        EXPECT_EQ(sample.size(), 20u);
        EXPECT_TRUE(is_valid_sample_str(sample));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '4'), 0u, 1u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '5'), 0u, 2u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'a'), 0u, 3u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '@'), 2u, 2u);
    }
}

TEST(StringTest, should_generate_sample_string_with_guarantee_3)
{
    // atmost 4 '(' - 2 '{' - 1 '\' - 5 '/'
    const std::vector<string::Spec> specs { { '(', 0, 4 }, { '{', 0, 2 }, { '\\', 0, 1 },
        { '/', 0, 5 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sample = string::sample(specs, 20);

        EXPECT_EQ(sample.size(), 20u);
        EXPECT_TRUE(is_valid_sample_str(sample));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '('), 0u, 4u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '{'), 0u, 2u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '\\'), 0u, 1u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '/'), 0u, 5u);
    }
}

TEST(StringTest, should_throw_on_invalid_guarantee_for_sample)
{
    // atleast 5 '3' - 6 ':' - 10 'A'
    // invalid
    // string will be atleast 21 which is wrong
    // atmost 6 '3'
    EXPECT_THROW(
        string::sample(
            std::vector<string::Spec> { { '3', 5, 6 }, { ':', 6, 0 }, { 'A', 10, 0 } }, 20),
        std::invalid_argument);

    // exactly 2 '~' // invalid // not in char set
    const std::vector<string::Spec> specs = { { 'a', 3 }, { 'A', 10 }, { '~', 2, 2 } };
    EXPECT_THROW(string::sample(specs, 20), std::invalid_argument);
}

TEST(StringTest, should_generate_default_string_from_charaters)
{
    const std::string allowed_chars { "abc" };

    const auto sampled = string::from_chars(allowed_chars);

    EXPECT_EQ(sampled.size(), 1u);
    EXPECT_TRUE(contains_only_chars_from(sampled, allowed_chars));
}

TEST(StringTest, should_generate_string_from_characters)
{
    const std::string allowed_chars { "iosjdaijqw" };

    const auto sampled = string::from_chars(allowed_chars, 6);

    EXPECT_EQ(sampled.size(), 6u);
    EXPECT_TRUE(contains_only_chars_from(sampled, allowed_chars));
}

TEST(StringTest, should_generate_string_from_charaters_with_guarantee_1)
{
    const std::string allowed_chars { "iosjdaijqw" };
    // exactly 1 's'
    // atleast 2 'w'
    // atmost 1 'a'
    const std::vector<string::Spec> specs { { 's', 1, 1 }, { 'w', 2 }, { 'a', 0, 1 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sampled = string::from_chars(specs, allowed_chars, 6);

        EXPECT_EQ(sampled.size(), 6u);
        EXPECT_TRUE(contains_only_chars_from(sampled, allowed_chars));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, 's'), 1u, 1u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, 'w'), 2u, 6u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, 'a'), 0u, 1u);
    }
}

TEST(StringTest, should_generate_string_from_charaters_with_guarantee_2)
{
    const std::string allowed_chars { "_abcd6=89#" };

    // exactly 5 '#'
    // atleast 3 '_' -
    // atmost 1 '8' - 2 '='
    const std::vector<string::Spec> specs { { '_', 3 }, { '#', 5, 5 }, { '8', 0, 1 },
        { '=', 0, 2 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sampled = string::from_chars(specs, allowed_chars, 20);

        EXPECT_EQ(sampled.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(sampled, allowed_chars));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, '_'), 3u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, '#'), 5u, 5u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, '8'), 0u, 1u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, '='), 0u, 2u);
    }
}

TEST(StringTest, should_generate_string_from_charaters_with_guarantee_3)
{
    const std::string allowed_chars { "!@#$%^&*()_+-=BA" };

    // exactly 10 'B' 1 '*'
    // atmost 2 '-'
    const std::vector<string::Spec> specs { { 'B', 10, 10 }, { '*', 1, 1 }, { '-', 0, 2 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sampled = string::from_chars(specs, allowed_chars, 20);

        EXPECT_EQ(sampled.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(sampled, allowed_chars));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, 'B'), 10u, 10u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, '*'), 1u, 1u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sampled, '-'), 0u, 2u);
    }
}

TEST(StringTest, should_throw_on_invalid_guarantee_for_from_characters)
{
    // atleast 10 '&' - 5 '*' - 5 'm' - 1 'b' // invalid // string size will be atleast 21 which
    // is invalid atmost 10 'b'
    EXPECT_THROW(string::from_chars(std::vector<string::Spec> { { '&', 10 }, { '*', 5 }, { 'm', 5 },
                                        { 'b', 1, 10 } },
                     std::string { "bnmv*&" }, 20),
        std::invalid_argument);

    // atleast 6 '1'
    // atmost 3 'a' - 5 'b' - 8 '1' // invalid // string size wont exceed 16 which is invalid
    EXPECT_THROW(string::from_chars(
                     std::vector<string::Spec> { { 'a', 0, 3 }, { 'b', 0, 5 }, { '1', 6, 8 } },
                     std::string { "ab1" }, 20),
        std::invalid_argument);

    // exactly 2 '1' // invalid // '1' not in `characters`
    EXPECT_THROW(string::from_chars(
                     std::vector<string::Spec> { { '1', 2, 2 }, { 'M', 2, 2 }, { 'm', 2, 2 } },
                     std::string { "67bnmM" }, 20),
        std::invalid_argument);
}

TEST(StringTest, should_generate_default_alpha)
{
    const auto alpha = string::alpha();

    EXPECT_EQ(alpha.size(), 1u);
    EXPECT_TRUE(contains_only_chars_from(alpha, string::data::ascii_letters));
}

TEST(StringTest, should_generate_mixed_alpha)
{
    const auto alpha = string::alpha(10);

    EXPECT_EQ(alpha.size(), 10u);
    EXPECT_TRUE(contains_only_chars_from(alpha, string::data::ascii_letters));
}

TEST(StringTest, should_generate_upper_alpha)
{
    const auto alpha = string::alpha(15, string::string_case::upper);

    EXPECT_EQ(alpha.size(), 15u);
    EXPECT_TRUE(contains_only_chars_from(alpha, string::data::ascii_upper_letters));
}

TEST(StringTest, should_generate_lower_alpha)
{
    const auto alpha = string::alpha(7, string::string_case::lower);

    EXPECT_EQ(alpha.size(), 7u);
    EXPECT_TRUE(contains_only_chars_from(alpha, string::data::ascii_lower_letters));
}

TEST(StringTest, should_generate_mixed_alpha_with_guarantee)
{
    // exactly 5 'a'
    // atleast 5 'A' - 3 'B' - 3 'z'
    // atmost 20 'A' - 20 'B' - 6 'z'
    const std::vector<string::Spec> specs { { 'A', 5, 20 }, { 'B', 3, 20 }, { 'a', 5, 5 },
        { 'z', 3, 6 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto alpha = string::alpha(specs, 20);

        EXPECT_EQ(alpha.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(alpha, string::data::ascii_letters));
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'A'), 5u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'B'), 3u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'a'), 5u, 5u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'z'), 3u, 6u);
    }
}

TEST(StringTest, should_generate_lower_alpha_with_guarantee)
{
    // exactly 5 'a'
    // atleast 5 'k' - 3 'o' - 3 'z'
    // atmost 20 'k' - 20 'o' - 6 'z'
    const std::vector<string::Spec> specs { { 'k', 5, 20 }, { 'o', 3, 20 }, { 'a', 5, 5 },
        { 'z', 3, 6 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto alpha = string::alpha(specs, 20, string::string_case::lower);

        EXPECT_EQ(alpha.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(alpha, string::data::ascii_lower_letters));
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'k'), 5u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'o'), 3u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'a'), 5u, 5u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'z'), 3u, 6u);
    }
}

TEST(StringTest, should_generate_upper_alpha_with_guarantee)
{
    // exactly 5 'A'
    // atleast 5 'K' - 3 'O' - 3 'Z'
    // atmost 20 'K' - 20 'O' - 6 'Z'
    const std::vector<string::Spec> specs { { 'K', 5, 20 }, { 'O', 3, 20 }, { 'A', 5, 5 },
        { 'Z', 3, 6 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto alpha = string::alpha(specs, 20, string::string_case::upper);

        EXPECT_EQ(alpha.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(alpha, string::data::ascii_upper_letters));
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'K'), 5u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'O'), 3u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'A'), 5u, 5u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(alpha, 'Z'), 3u, 6u);
    }
}

TEST(StringTest, should_throw_on_invalid_specs_for_alpha)
{
    // exactly 3 'Z'
    // atleast 8 'A' - 10 'B' 1 'Y' // invalid // string size will be atleast 22 which is invalid
    // atmost 10 'A','Y' - 15 'B'
    EXPECT_THROW(string::alpha(std::vector<string::Spec> { { 'A', 8, 10 }, { 'B', 10, 15 },
                                   { 'Y', 1, 10 }, { 'Z', 3, 3 } },
                     20),
        std::invalid_argument);

    // atmost 1
    // 'A','B','C',D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    // invalid // string size won't exceed 26 which is invalid
    EXPECT_THROW(string::alpha(
                     std::vector<string::Spec> {
                         { 'A', 0, 1 },
                         { 'B', 0, 1 },
                         { 'C', 0, 1 },
                         { 'D', 0, 1 },
                         { 'E', 0, 1 },
                         { 'F', 0, 1 },
                         { 'G', 0, 1 },
                         { 'H', 0, 1 },
                         { 'I', 0, 1 },
                         { 'J', 0, 1 },
                         { 'K', 0, 1 },
                         { 'L', 0, 1 },
                         { 'M', 0, 1 },
                         { 'N', 0, 1 },
                         { 'O', 0, 1 },
                         { 'P', 0, 1 },
                         { 'Q', 0, 1 },
                         { 'R', 0, 1 },
                         { 'S', 0, 1 },
                         { 'T', 0, 1 },
                         { 'U', 0, 1 },
                         { 'V', 0, 1 },
                         { 'W', 0, 1 },
                         { 'X', 0, 1 },
                         { 'Y', 0, 1 },
                         { 'Z', 0, 1 },
                     },
                     30, string::string_case::upper),
        std::invalid_argument);

    // atleast 4 '5' // invalid // alpha can't have digits
    EXPECT_THROW(
        string::alpha(
            std::vector<string::Spec> { { 'a', 4, 10 }, { 'B', 4, 10 }, { '5', 4, 6 } }, 20),
        std::invalid_argument);

    // atleast 4 'a' // invalid // Can't have lower case characters when string casing is set to
    // string::string_case::upper
    EXPECT_THROW(string::alpha(std::vector<string::Spec> { { 'a', 4, 10 }, { 'B', 4, 10 } }, 20,
                     string::string_case::upper),
        std::invalid_argument);

    // atleast 4 'B'
    // invalid
    // Can't have upper case characters when string casing is set to string::string_case::lower
    EXPECT_THROW(string::alpha(std::vector<string::Spec> { { 'a', 4, 10 }, { 'B', 4, 10 } }, 20,
                     string::string_case::lower),
        std::invalid_argument);
}

TEST(StringTest, should_generate_default_aphanumeric)
{
    const auto sample = string::alphanumeric();

    EXPECT_EQ(sample.size(), 1u);
    EXPECT_TRUE(contains_only_chars_from(sample, string::data::ascii_alphanum));
}

TEST(StringTest, should_generate_mixed_alphanumeric)
{
    const auto sample = string::alphanumeric(10);

    EXPECT_EQ(sample.size(), 10u);
    EXPECT_TRUE(contains_only_chars_from(sample, string::data::ascii_alphanum));
}

TEST(StringTest, should_generate_upper_alphanumeric)
{
    const auto alphanumeric = string::alphanumeric(15, string::string_case::upper);

    EXPECT_EQ(alphanumeric.size(), 15u);
    EXPECT_TRUE(contains_only_chars_from(alphanumeric, string::data::ascii_upper_alphanum));
}

TEST(StringTest, should_generate_lower_alphanumeric)
{
    const auto alphanumeric = string::alphanumeric(7, string::string_case::lower);

    EXPECT_EQ(alphanumeric.size(), 7u);
    EXPECT_TRUE(contains_only_chars_from(alphanumeric, string::data::ascii_lower_alphanum));
}

TEST(StringTest, should_generate_mixed_alphanumeric_with_guarantee)
{
    // exactly 1 'a'
    // atleast 5 'A' - 3 'B' - 3 'z'
    // atmost 20 'A' - 20 'B' - 6 'z'
    const std::vector<string::Spec> specs { { '1', 5, 20 }, { 'B', 3, 20 }, { 'a', 5, 5 },
        { 'z', 3, 6 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sample = string::alphanumeric(specs, 20);

        EXPECT_EQ(sample.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(sample, string::data::ascii_alphanum));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '1'), 5u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'B'), 3u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'a'), 5u, 5u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'z'), 3u, 6u);
    }
}

TEST(StringTest, should_generate_lower_alphanumeric_with_guarantee)
{
    // exactly 5 'a'
    // atleast 5 'k' - 3 'o' - 3 '0'
    // atmost 20 'k' - 20 'o' - 6 '0'
    const std::vector<string::Spec> specs { { 'k', 5, 20 }, { 'o', 3, 20 }, { 'a', 5, 5 },
        { '0', 3, 6 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sample = string::alphanumeric(specs, 20, string::string_case::lower);

        EXPECT_EQ(sample.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(sample, string::data::ascii_lower_alphanum));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'k'), 5u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'o'), 3u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'a'), 5u, 5u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '0'), 3u, 6u);
    }
}

TEST(StringTest, should_generate_upper_alphanumeric_with_guarantee)
{
    // exactly 5 'A'
    // atleast 5 '7' - 3 'O' - 3 'Z'
    // atmost 20 '7' - 20 'O' - 6 'Z'
    const std::vector<string::Spec> specs { { '7', 5, 20 }, { 'O', 3, 20 }, { 'A', 5, 5 },
        { 'Z', 3, 6 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto sample = string::alphanumeric(specs, 20, string::string_case::upper);

        EXPECT_EQ(sample.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(sample, string::data::ascii_upper_alphanum));
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, '7'), 5u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'O'), 3u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'A'), 5u, 5u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(sample, 'Z'), 3u, 6u);
    }
}

TEST(StringTest, should_throw_on_invalid_guarantee_for_alphanumeric)
{
    // exactly 3 '8'
    // atleast 8 'A' - 10 'b' 1 'Y' // invalid // string size will be atleast 22 which is invalid
    // atmost 10 'A','Y' - 15 'b'
    EXPECT_THROW(string::alphanumeric(std::vector<string::Spec> { { 'A', 8, 10 }, { 'b', 10, 15 },
                                          { 'Y', 1, 10 }, { '8', 3, 3 } },
                     20),
        std::invalid_argument);

    // atmost 1
    // 'A','B','C',D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
    // 'S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'
    // invalid // string size won't exceed 36 which is invalid
    EXPECT_THROW(string::alphanumeric(
                     std::vector<string::Spec> {
                         { 'A', 0, 1 },
                         { 'B', 0, 1 },
                         { 'C', 0, 1 },
                         { 'D', 0, 1 },
                         { 'E', 0, 1 },
                         { 'F', 0, 1 },
                         { 'G', 0, 1 },
                         { 'H', 0, 1 },
                         { 'I', 0, 1 },
                         { 'J', 0, 1 },
                         { 'K', 0, 1 },
                         { 'L', 0, 1 },
                         { 'M', 0, 1 },
                         { 'N', 0, 1 },
                         { 'O', 0, 1 },
                         { 'P', 0, 1 },
                         { 'Q', 0, 1 },
                         { 'R', 0, 1 },
                         { 'S', 0, 1 },
                         { 'T', 0, 1 },
                         { 'U', 0, 1 },
                         { 'V', 0, 1 },
                         { 'W', 0, 1 },
                         { 'X', 0, 1 },
                         { 'Y', 0, 1 },
                         { 'Z', 0, 1 },
                         { '0', 0, 1 },
                         { '1', 0, 1 },
                         { '2', 0, 1 },
                         { '3', 0, 1 },
                         { '4', 0, 1 },
                         { '5', 0, 1 },
                         { '6', 0, 1 },
                         { '7', 0, 1 },
                         { '8', 0, 1 },
                         { '9', 0, 1 },
                     },
                     40, string::string_case::upper),
        std::invalid_argument);

    // atleast 4 '#' // invalid // alphanumeric can't have symbols
    EXPECT_THROW(string::alphanumeric(std::vector<string::Spec> { { 'a', 4, 10 }, { 'B', 4, 10 },
                                          { '5', 4, 6 }, { '#', 4 } },
                     20),
        std::invalid_argument);

    // atleast 4 'a' // invalid // Can't have lower case characters when string casing is set to
    // string::string_case::upper
    EXPECT_THROW(string::alphanumeric(
                     std::vector<string::Spec> { { 'a', 4, 10 }, { 'B', 4, 10 }, { '2', 1 } }, 20,
                     string::string_case::upper),
        std::invalid_argument);

    // atleast 4 'B' // invalid // Can't have upper case characters when string casing is set to
    // string::string_case::lower
    EXPECT_THROW(string::alphanumeric(
                     std::vector<string::Spec> { { 'a', 4, 10 }, { 'B', 4, 10 }, { '8', 8, 10 } },
                     20, string::string_case::lower),
        std::invalid_argument);
}

TEST(StringTest, should_generate_numeric)
{
    const auto number_may_start_with_zero = string::numeric();
    const auto number_starts_with_non_zero = string::numeric(13, false);

    EXPECT_EQ(number_may_start_with_zero.size(), 1u);
    EXPECT_TRUE(contains_only_chars_from(number_may_start_with_zero, string::data::digits));

    EXPECT_EQ(number_starts_with_non_zero.size(), 13u);
    EXPECT_TRUE(contains_only_chars_from(
        number_starts_with_non_zero.substr(0, 1), string::data::non_zero_digits));
    EXPECT_TRUE(
        contains_only_chars_from(number_starts_with_non_zero.substr(1), string::data::digits));
}

TEST(StringTest, should_generate_numeric_with_guarantee1)
{
    // atleast 10 '0' - 5 '9'
    // atmost 15 '0' - 10 '9'
    const std::vector<string::Spec> specs = { { '0', 10, 15 }, { '9', 5, 10 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto numeric = string::numeric(specs, 20);

        EXPECT_EQ(numeric.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(numeric, string::data::digits));
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '0'), 10u, 15u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '9'), 5u, 10u);
    }
}

TEST(StringTest, shouldGenerateNumericWithGuarantee2)
{
    // exactly 0 '1' - 5 '9'
    // atleast 5 '2'
    // atmost 20 '2' - 1 '8'
    const std::vector<string::Spec> specs { { '1', 0, 0 }, { '2', 5, 20 }, { '8', 0, 1 },
        { '9', 5, 5 } };
    // it is a random function so lets test for 20 random generations
    for (unsigned i = 0; i < run_count; ++i) {
        const auto numeric = string::numeric(specs, 20);

        EXPECT_EQ(numeric.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(numeric, string::data::digits));
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '1'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '2'), 5u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '8'), 0u, 1u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '9'), 5u, 5u);
    }
}

TEST(StringTest, should_generate_numeric_without_leading_zeros_with_guarantee_1)
{
    // atleast 19 '0'
    const std::vector<string::Spec> specs = { { '0', 19 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto numeric = string::numeric(specs, 20, false);

        EXPECT_EQ(numeric.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(numeric.substr(0, 1), string::data::non_zero_digits));
        EXPECT_TRUE(contains_only_chars_from(numeric.substr(1), string::data::digits));
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '0'), 19u, 20u);
    }
}

TEST(StringTest, should_generate_numeric_without_leading_zeros_with_guarantee2)
{
    // atleast 10 '0' - 3 '1' - 3 '3'
    // atmost 4 '1' - 4 '3'
    const std::vector<string::Spec> specs = { { '0', 10 }, { '1', 3, 4 }, { '3', 2, 4 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto numeric = string::numeric(specs, 20, false);

        EXPECT_EQ(numeric.size(), 20u);
        EXPECT_TRUE(contains_only_chars_from(numeric.substr(0, 1), string::data::non_zero_digits));
        EXPECT_TRUE(contains_only_chars_from(numeric.substr(1), string::data::digits));
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '0'), 10u, 20u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '1'), 3u, 4u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(numeric, '3'), 2u, 4u);
    }
}

TEST(StringTest, invalid_guarantee_for_numeric)
{
    // atleast 10 '0' - 3 '1' - 8 '3' // invalid // string size will be atleast 21 which is wrong
    // atmost 4 '1' - 10 '3'
    EXPECT_THROW(string::numeric(
                     std::vector<string::Spec> { { '0', 10 }, { '1', 3, 4 }, { '3', 8, 10 } }, 20),
        std::invalid_argument);

    // atmost 1 '0','1','2','3','4','5','6','7','8','9' // invalid // string size wont exceed 10
    // which is wrong
    EXPECT_THROW(string::numeric(
                     std::vector<string::Spec> {
                         { '1', 0, 1 },
                         { '2', 0, 1 },
                         { '3', 0, 1 },
                         { '4', 0, 1 },
                         { '5', 0, 1 },
                         { '6', 0, 1 },
                         { '7', 0, 1 },
                         { '8', 0, 1 },
                         { '9', 0, 1 },
                         { '0', 0, 1 },
                     },
                     20),
        std::invalid_argument);

    // exactly 5 'a' // invalid // numeric string can't have alphabets
    EXPECT_THROW(string::numeric(std::vector<string::Spec> { { '0', 10 }, { '1', 3, 4 },
                                     { '3', 2, 4 }, { 'a', 5, 5 } },
                     20),
        std::invalid_argument);

    // atleast 5 '0' // invalid // leading zeros not allowed so '0' count should be less than
    // numericLength i.e 5
    EXPECT_THROW(
        string::numeric(std::vector<string::Spec> { { '0', 5 } }, 5, false), std::invalid_argument);
}

TEST(StringTest, should_generate_hexadecimal)
{
    const auto hexadecimal = string::hexadecimal(8);

    EXPECT_EQ(hexadecimal.size(), 10u);
    EXPECT_TRUE(faker::testing::starts_with(hexadecimal, "0x"));
    EXPECT_TRUE(contains_only_chars_from(hexadecimal.substr(2), string::data::hex_lower_digits));
}

TEST(StringTest, should_generate_hexadecimal_with_hash_prefix)
{
    const auto hexadecimal = string::hexadecimal(8, hex_case_t::upper, hex_prefix_t::hash);

    EXPECT_EQ(hexadecimal.size(), 9u);
    EXPECT_TRUE(faker::testing::starts_with(hexadecimal, "#"));
    EXPECT_TRUE(contains_only_chars_from(hexadecimal.substr(1), string::data::hex_upper_digits));
}

TEST(StringTest, should_generate_hexadecimal_without_prefix)
{
    const auto hexadecimal = string::hexadecimal(8, hex_case_t::upper, hex_prefix_t::none);

    EXPECT_EQ(hexadecimal.size(), 8u);
    EXPECT_TRUE(contains_only_chars_from(hexadecimal, string::data::hex_upper_digits));
}

TEST(StringTest, should_generate_hexadecimal_with_guarantee_1)
{
    // exactly 4 'a'
    // atleast 3 'f'
    // atmost 10 'f'
    std::vector<string::Spec> specs { { 'a', 4, 4 }, { 'f', 3, 10 } };
    for (unsigned i = 0; i < run_count; ++i) {
        const auto hexadecimal = string::hexadecimal(specs, 20);

        EXPECT_EQ(hexadecimal.size(), 22u);
        EXPECT_TRUE(faker::testing::starts_with(hexadecimal, "0x"));
        EXPECT_TRUE(
            contains_only_chars_from(hexadecimal.substr(2), string::data::hex_lower_digits));
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), 'a'), 4u, 4u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), 'f'), 3u, 10u);
    }
}

TEST(StringTest, should_generate_hexadecimal_with_guarantee_2)
{
    // exactly 10 'F' - 0 'A'
    // atleast 5 '0'
    std::vector<string::Spec> guarantee { { 'A', 0, 0 }, { 'F', 10, 10 }, { '0', 5 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto hexadecimal = string::hexadecimal(guarantee, 20, hex_case_t::upper);

        EXPECT_EQ(hexadecimal.size(), 22u);
        EXPECT_EQ(hexadecimal.substr(0, 2), "0x");
        EXPECT_TRUE(
            contains_only_chars_from(hexadecimal.substr(2), string::data::hex_upper_digits));
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), 'A'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), 'F'), 10u, 10u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '0'), 5u, 20u);
    }
}

TEST(StringTest, should_generate_hexadecimal_with_guarantee_3)
{
    // exactly 0 '0' '1' '2' '3' '4' '5' '6' '7'
    const std::vector<string::Spec> specs {
        { '0', 0, 0 },
        { '1', 0, 0 },
        { '2', 0, 0 },
        { '3', 0, 0 },
        { '4', 0, 0 },
        { '5', 0, 0 },
        { '6', 0, 0 },
        { '7', 0, 0 },
    };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto hexadecimal = string::hexadecimal(specs, 20, hex_case_t::upper);

        EXPECT_EQ(hexadecimal.size(), 22u);
        FAKER_EXPECT_STRING_STARTS_WITH(hexadecimal, "0x");
        EXPECT_TRUE(
            contains_only_chars_from(hexadecimal.substr(2), string::data::hex_upper_digits));
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '0'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '1'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '2'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '3'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '4'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '5'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '6'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(hexadecimal.substr(2), '7'), 0u, 0u);
    }
}

TEST(StringTest, should_throw_on_invalid_guarantee_for_hexadecimal)
{
    // atleast 5 'G' // invalid // 'G' is not a valid char for hexadecimal numbers
    EXPECT_THROW(string::hexadecimal(
                     std::vector<string::Spec> { { 'A', 0, 0 }, { 'F', 10, 10 }, { 'G', 5 } }, 20,
                     hex_case_t::upper),
        std::invalid_argument);

    // atleast 5 'F' // invalid // 'F' is not a valid char for hexadecimal numbers with
    // hex_case::lower
    EXPECT_THROW(string::hexadecimal(
                     std::vector<string::Spec> { { 'a', 0, 0 }, { 'F', 10, 10 }, { '1', 5 } }, 20),
        std::invalid_argument);

    // atleast 5 'F' // invalid // 'F' is not a valid char for hexadecimal numbers with
    // hex_case::lower
    EXPECT_THROW(string::hexadecimal(
                     std::vector<string::Spec> { { 'a', 0, 0 }, { 'F', 10, 10 }, { '1', 5 } }, 20),
        std::invalid_argument);

    // atleast 5 'a' - 8 'b' // invalid // string size will be atleast 13 which is wrong
    // atmost 10 'b' - 3 '1'
    EXPECT_THROW(string::hexadecimal(
                     std::vector<string::Spec> { { 'a', 5 }, { 'b', 8, 10 }, { '1', 0, 3 } }, 10),
        std::invalid_argument);

    // atmost 1 '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' // invalid // string
    // size wont exceed 16 which is wrong
    EXPECT_THROW(string::hexadecimal(
                     std::vector<string::Spec> {
                         { '0', 0, 1 },
                         { '1', 0, 1 },
                         { '2', 0, 1 },
                         { '3', 0, 1 },
                         { '4', 0, 1 },
                         { '5', 0, 1 },
                         { '6', 0, 1 },
                         { '7', 0, 1 },
                         { '8', 0, 1 },
                         { '9', 0, 1 },
                         { 'a', 0, 1 },
                         { 'b', 0, 1 },
                         { 'c', 0, 1 },
                         { 'd', 0, 1 },
                         { 'e', 0, 1 },
                         { 'f', 0, 1 },
                     },
                     20),
        std::invalid_argument);
}

TEST(StringTest, should_generate_binary)
{
    const auto binary = string::binary(8);

    FAKER_EXPECT_REGEX_MATCHES(binary, "^0b[01]{8}$");
}

TEST(StringTest, should_generate_binary_with_guarantee_1)
{
    // atleast 3 '0' and 2 '1'
    // atmost 7 '0' and 7 '1'
    std::vector<string::Spec> specs { { '0', 3, 7 }, { '1', 2, 7 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto binary = string::binary(specs, 9);

        FAKER_EXPECT_REGEX_MATCHES(binary, "^0b[01]{9}$");
        FAKER_EXPECT_BETWEEN(faker::testing::count(binary, '0'), 4u, 8u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(binary, '1'), 2u, 7u);
    }
}

TEST(StringTest, should_generate_binary_with_guarantee_2)
{
    // exactly 8 '0' and 2 '1'
    std::vector<string::Spec> specs { { '0', 8, 8 }, { '1', 2, 2 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto binary = string::binary(specs, 10);

        FAKER_EXPECT_REGEX_MATCHES(binary, "^0b[01]{10}$");
        FAKER_EXPECT_BETWEEN(faker::testing::count(binary, '0'), 9u, 9u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(binary, '1'), 2u, 2u);
    }
}

TEST(StringTest, should_generate_binary_with_guarantee_3)
{
    // atleast 10 '0'
    std::vector<string::Spec> guarantee { { '0', 0, 10 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto binary = string::binary(guarantee, 10);

        FAKER_EXPECT_REGEX_MATCHES(binary, "^0b[01]{10}$");
        FAKER_EXPECT_BETWEEN(faker::testing::count(binary, '0'), 1u, 11u);
    }
}

TEST(StringTest, should_generate_binary_with_guarantee_4)
{
    // atmost 0 '0'
    std::vector<string::Spec> specs { { '0', 0, 0 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto binary = string::binary(specs, 10);

        FAKER_EXPECT_REGEX_MATCHES(binary, "^0b1{10}$");
        FAKER_EXPECT_BETWEEN(faker::testing::count(binary, '0'), 1u, 1u);
    }
}

TEST(StringTest, should_throw_on_invalid_guarantee_for_binary)
{
    // atleast 6 '0' and 6 '1'  // invalid // total string size will be 12 which is wrong
    // atleast 10 '0' and 10 '1'
    EXPECT_THROW(string::binary(std::vector<string::Spec> { { '0', 6, 10 }, { '1', 6, 10 } }, 10),
        std::invalid_argument);

    // atleast 6 '0' and 6 '1'
    // atleast 10 '0' and 8 '1' // invalid // total string size won't exceed 18 which is wrong
    EXPECT_THROW(string::binary(std::vector<string::Spec> { { '0', 6, 10 }, { '1', 6, 8 } }, 20),
        std::invalid_argument);

    //  atleast 4 '0' and 3 'a' // invalid // binary string should consist of only '0' and '1'
    EXPECT_THROW(string::binary(std::vector<string::Spec> { { '0', 4 }, { 'a', 3 } }, 10),
        std::invalid_argument);
}

TEST(StringTest, should_generate_octal_with_prefix)
{
    const auto octal = string::octal(8);

    FAKER_EXPECT_REGEX_MATCHES(octal, "^0o[0-7]{8}$");
}

TEST(StringTest, should_generate_octal_with_guarantee_1)
{
    // exactly 2 '3' - 0 '5'
    // atleast 2 '0' - 3 '6' - 1 '7'
    // atmost 10 '6' - 10 '7'
    std::vector<string::Spec> specs { { '0', 2 }, { '3', 2, 2 }, { '5', 0, 0 }, { '6', 3, 10 },
        { '7', 1, 10 } };

    for (unsigned i = 0; i < run_count; ++i) {
        const auto octal = string::octal(specs, 10);

        FAKER_EXPECT_REGEX_MATCHES(octal, "^0o[0-7]{10}$");
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '0'), 3u, 11u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '3'), 2u, 2u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '5'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '6'), 3u, 10u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '7'), 1u, 10u);
    }
}

TEST(StringTest, should_generate_octal_with_guarantee_2)
{
    // exactly 0 '2' '3' '4' '5' '6' '7'
    // atleast 18 '0'
    std::vector<string::Spec> guarantee { { '0', 18 }, { '2', 0, 0 }, { '3', 0, 0 }, { '4', 0, 0 },
        { '5', 0, 0 }, { '6', 0, 0 }, { '7', 0, 0 } };
    // it is a random function so lets test for 20 random generations
    for (unsigned i = 0; i < run_count; ++i) {
        const auto octal = string::octal(guarantee, 20);

        FAKER_EXPECT_REGEX_MATCHES(octal, "^0o[0-7]{20}$");
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '0'), 19u, 21u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '2'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '3'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '4'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '5'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '6'), 0u, 0u);
        FAKER_EXPECT_BETWEEN(faker::testing::count(octal, '7'), 0u, 0u);
    }
}

TEST(StringTest, should_throw_on_invalid_guarantee_for_octal)
{
    // exactly 0 '4'
    // atleast 8 '0' - 9 '2' 9 '3'  // invalid // total string size will be atleast 26 which is
    // wrong atmost
    EXPECT_THROW(
        string::octal(
            std::vector<string::Spec> { { '0', 8 }, { '2', 9 }, { '3', 9 }, { '4', 0, 0 } }, 10),
        std::invalid_argument);

    // atmost 2 '0' '1' '2' '3' '4' '5' '6' '7' // invalid // octal string won't exceed 16 which is
    // wrong
    EXPECT_THROW(string::octal(std::vector<string::Spec> { { '0', 0, 2 }, { '1', 0, 2 },
                                   { '2', 0, 2 }, { '3', 0, 2 }, { '4', 0, 2 }, { '5', 0, 2 },
                                   { '6', 0, 2 }, { '7', 0, 2 } },
                     20),
        std::invalid_argument);

    // atleast 2 '8' // invalid // octal numbers cannot have '8'
    // atmost 3 '8'
    EXPECT_THROW(string::octal(std::vector<string::Spec> { { '0', 0, 2 }, { '1', 0, 2 },
                                   { '8', 2, 3 }, { '2', 0, 2 }, { '3', 0, 2 } },
                     20),
        std::invalid_argument);
}
