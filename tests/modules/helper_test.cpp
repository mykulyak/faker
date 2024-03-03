#include "../test_helpers.h"
#include <common/random.h>
#include <faker/string.h>
#include <regex>
#include <unordered_map>

using namespace faker;

TEST(HelperTest, should_choose_random_vector_element)
{
    std::vector<std::string> data { "hello", "world" };

    auto result = random::element(data);

    FAKER_EXPECT_CONTAINER_CONTAINS(data, result);
}

TEST(HelperTest, should_throw_if_input_vector_is_empty)
{
    std::vector<std::string> data {};

    EXPECT_THROW(random::element(data), std::invalid_argument);
}

TEST(HelperTest, should_choose_random_array_element)
{
    std::array<std::string_view, 3> data { "hello", "beautiful", "world" };

    auto result = random::element(data);

    FAKER_EXPECT_CONTAINER_CONTAINS(data, result);
}

TEST(HelperTest, should_throw_if_input_array_is_empty)
{
    std::array<std::string_view, 0> data {};

    EXPECT_THROW(random::element(data), std::invalid_argument);
}

TEST(HelperTest, should_chose_weighted_element_from_vector)
{
    std::vector<random::WeightedElement<std::string>> data { { 1, "hello" }, { 9, "world" } };

    const auto result = random::weighted_element(data);

    EXPECT_TRUE(faker::testing::any_of(
        data, [&result](const random::WeightedElement<std::string>& element) {
            return result == element.value;
        }));
}

TEST(HelperTest, should_throw_if_sum_of_weights_is_zero)
{
    std::vector<random::WeightedElement<std::string>> data { { 0, "hello" }, { 0, "world" } };

    EXPECT_THROW(random::weighted_element(data), std::invalid_argument);
}

TEST(HelperTest, should_throw_if_input_weight_vector_is_empty)
{
    std::vector<random::WeightedElement<std::string>> data {};

    EXPECT_THROW(random::weighted_element(data), std::invalid_argument);
}

TEST(HelperTest, should_shuffle_string)
{
    std::string input = "Hello World!";

    std::string result = random::shuffle_string(input);

    EXPECT_TRUE(faker::testing::all_of(
        input, [&result](char character) { return result.find(character) != std::string::npos; }));
}

TEST(HelperTest, should_choose_random_element_from_set)
{
    std::unordered_set<char> chars { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm' };

    std::vector<char> chosen;

    chosen.reserve(30);
    for (int i = 0; i < 30; ++i) {
        chosen.push_back(random::element_from_set(chars));
    }

    for (auto character : chosen) {
        EXPECT_TRUE(chars.find(character) != chars.end());
    }
}

TEST(HelperTest, should_throw_if_input_set_is_empty)
{
    std::unordered_set<char> chars {};

    EXPECT_THROW(random::element_from_set(chars), std::invalid_argument);
}

TEST(HelperTest, should_replace_symbols_with_number)
{
    std::string input = "123#456!";
    std::string result = random::replace_symbol_with_number(input);

    // The result should contain digits instead of '#' and '!'
    EXPECT_TRUE(faker::testing::all_of(result, ::isdigit));
}

TEST(HelperTest, should_regexp_style_string_parse)
{
    std::string input = "#{5}[2-4]test[1-3]";
    std::string result = random::regexp_style_string_parse(input);

    EXPECT_EQ(result.size(), 11u);
}

TEST(HelperTest, should_replace_credit_card_symbols)
{
    // Test with the default format "6453-####-####-####-###L"
    std::string result_default = random::replace_credit_card_symbols();
    EXPECT_EQ(result_default.size(), 24u);
    EXPECT_EQ(result_default[4], '-');
    EXPECT_EQ(result_default[9], '-');
    EXPECT_EQ(result_default[14], '-');
    EXPECT_EQ(result_default[19], '-');

    // Test with a custom format "1234-[4-9]-##!!-L"
    std::string format_custom = "1234-[4-9]-##!!-L";
    std::string result_custom = random::replace_credit_card_symbols(format_custom);
    std::regex custom_format_regex("1234-[4-9]-\\d{2}[2-9]{2}-\\d");
    EXPECT_TRUE(std::regex_match(result_custom, custom_format_regex));

    // Manually verify the custom format result, as the output is random
    // e.g., "1234-9-5298-2"
    EXPECT_EQ(result_custom.substr(0, 5), "1234-");
    EXPECT_EQ(result_custom.substr(6, 1), "-");
    EXPECT_TRUE(result_custom[5] >= '4' && result_custom[5] <= '9');
    EXPECT_TRUE(result_custom[8] >= '0' && result_custom[8] <= '9');
    EXPECT_TRUE(result_custom[9] >= '0' && result_custom[9] <= '9');
}

TEST(HelperTest, should_choose_random_map_key)
{
    std::unordered_map<int, std::string> test_map = { { 1, "one" }, { 2, "two" }, { 3, "three" } };

    EXPECT_NO_THROW({
        int key = random::map_key(test_map);
        EXPECT_TRUE(test_map.find(key) != test_map.end());
    });

    std::unordered_map<int, std::string> empty_map;

    EXPECT_THROW({ random::map_key(empty_map); }, std::runtime_error);
}
