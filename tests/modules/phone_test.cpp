#include "../test_helpers.h"
#include <faker/phone.h>
#include <modules/phone_data.h>
#include <regex>

using namespace faker;

namespace {
bool contains_one_or_more_digits_or_special_chars(const std::string& str)
{
    return !str.empty() && faker::testing::all_of(str, [](char c) {
        return std::isdigit(c) || c == '-' || c == '(' || c == ')' || c == '+' || c == ' ';
    });
}
}

TEST(PhoneTest, should_generate_phone_number)
{
    auto phone_number_any_format = phone::number();
    auto phone_number_zimbabwe = phone::number(phone::phone_number_format_t::zimbabwe);
    auto phone_number_with_custom_format_1 = phone::number("501-###-###");
    auto phone_number_with_custom_format_2 = phone::number("+48 91 ### ## ##");
    auto phone_number_with_custom_format_3 = phone::number("+376 (###) ###-####");
    auto phone_number_with_custom_format_4 = phone::number("+376 (!!!) !!!-!!!!");

    EXPECT_TRUE(contains_one_or_more_digits_or_special_chars(phone_number_any_format));
    EXPECT_TRUE(contains_one_or_more_digits_or_special_chars(phone_number_zimbabwe));

    EXPECT_TRUE(contains_one_or_more_digits_or_special_chars(phone_number_with_custom_format_1));
    EXPECT_TRUE(
        std::regex_match(phone_number_with_custom_format_1, std::regex(R"(501-\d{3}-\d{3})")));

    EXPECT_TRUE(contains_one_or_more_digits_or_special_chars(phone_number_with_custom_format_2));
    EXPECT_TRUE(std::regex_match(
        phone_number_with_custom_format_2, std::regex(R"(\+48 91 \d{3} \d{2} \d{2})")));

    EXPECT_TRUE(contains_one_or_more_digits_or_special_chars(phone_number_with_custom_format_1));
    EXPECT_TRUE(std::regex_match(
        phone_number_with_custom_format_3, std::regex(R"(\+376 \(\d{3}\) \d{3}-\d{4})")));

    EXPECT_TRUE(contains_one_or_more_digits_or_special_chars(phone_number_with_custom_format_1));
    EXPECT_TRUE(std::regex_match(
        phone_number_with_custom_format_4, std::regex(R"(\+376 \(\d{3}\) \d{3}-\d{4})")));
}

TEST(PhoneTest, should_generate_imei)
{
    auto imei = phone::imei();

    imei.erase(std::remove(imei.begin(), imei.end(), '-'), imei.end());

    EXPECT_EQ(imei.size(), 15);
    EXPECT_TRUE(contains_one_or_more_digits_or_special_chars(imei));
}

TEST(PhoneTest, should_generate_platform)
{
    auto platform = phone::platform();

    FAKER_EXPECT_CONTAINER_CONTAINS(phone::data::platforms, platform);
}

TEST(PhoneTest, should_generate_model_name)
{
    auto model_name = phone::model_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(phone::data::model_names, model_name);
}

TEST(PhoneTest, should_generate_manufacturer)
{
    auto manufacturer = phone::manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(phone::data::manufacturers, manufacturer);
}
