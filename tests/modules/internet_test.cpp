#include "../test_helpers.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <common/strings.h>
#include <faker/internet.h>
#include <modules/internet_data.h>
#include <modules/person_data.h>
#include <modules/string_data.h>
#include <modules/word_data.h>
#include <optional>
#include <regex>

using namespace ::testing;
using namespace faker;

namespace {
template <typename StringLikeT> bool contains_only_valid_password_chars(const StringLikeT& str)
{
    static const std::string_view valid_password_chars
        = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456"
          "789~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/";

    return std::all_of(str.begin(), str.end(),
        [](char ch) { return valid_password_chars.find(ch) != std::string::npos; });
}

const std::vector<std::string> web_protocols { "http", "https" };
const std::vector<std::string> http_method_names { "GET", "POST", "DELETE", "PATCH", "PUT" };
const std::vector<unsigned> http_status_codes_1xx { 100, 101, 102, 103 };
const std::vector<unsigned> http_status_codes_2xx { 200, 201, 202, 203, 204, 205, 206, 207, 208,
    226 };
const std::vector<unsigned> http_status_codes_3xx { 300, 301, 302, 303, 304, 305, 306, 307, 308 };
const std::vector<unsigned> http_status_codes_4xx { 400, 401, 402, 403, 404, 405, 406, 407, 408,
    409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 421, 422, 423, 424, 425, 426, 428, 429, 431,
    451 };
const std::vector<unsigned> http_status_codes_5xx { 500, 501, 502, 503, 504, 505, 506, 507, 508,
    510, 511 };
constexpr unsigned class_a_first_section = 10u;
constexpr unsigned class_b_first_section = 172u;
constexpr unsigned class_b_second_section_lower_bound = 16;
constexpr unsigned class_b_second_section_upper_bound = 31;
constexpr unsigned class_c_first_section = 192u;
constexpr unsigned class_c_second_section = 168u;

std::array<unsigned, 4> parse_ipv4_string(const std::string& ipv4)
{
    std::array<unsigned, 4> result;

    auto parts = utils::split(ipv4, ".");
    for (size_t i = 0; i < parts.size(); ++i) {
        result[i] = std::stoi(parts[i]);
    }

    return result;
}
}

class InternetTest : public Test {
public:
    InternetTest()
    {
        std::sort(adjectives_by_size_desc.begin(), adjectives_by_size_desc.end(),
            [](const auto& first, const auto& second) { return first.size() > second.size(); });
    }

    void assert_valid_domain_word(std::string_view domain_word)
    {
        auto it = std::find_if(adjectives_by_size_desc.begin(), adjectives_by_size_desc.end(),
            [domain_word](auto adj) { return domain_word.find(adj) == 0; });
        ASSERT_NE(it, adjectives_by_size_desc.end());

        EXPECT_EQ(domain_word[it->size()], '-');

        const auto domain_noun = domain_word.substr(it->size() + 1);
        EXPECT_TRUE(
            faker::testing::any_of(word::data::nouns, [domain_noun](const std::string_view& noun) {
                return faker::testing::compare_no_case(domain_noun, noun);
            }));
    }

    std::vector<std::string_view> adjectives_by_size_desc { word::data::adjectives.begin(),
        word::data::adjectives.end() };
};

TEST_F(InternetTest, should_generate_username)
{
    const auto username = internet::username();
    const auto username_fixed_first_name = internet::username("FixedFirstName");
    const auto username_fixed_last_name = internet::username(std::nullopt, "Cieślar");
    const auto username_fixed = internet::username("FixedFirstName", "FixedLastName");
    const auto username_with_non_ascii_chars
        = internet::username(std::nullopt, std::nullopt, country_t::romania);

    EXPECT_TRUE(faker::testing::contains_any_of(username, person::data::english_female_first_names)
        || faker::testing::contains_any_of(username, person::data::english_male_first_names));
    EXPECT_TRUE(faker::testing::contains_any_of(username, person::data::english_last_names));

    EXPECT_TRUE(username_fixed_first_name.find("FixedFirstName") != std::string::npos);
    EXPECT_TRUE(faker::testing::contains_any_of(
        username_fixed_first_name, person::data::english_last_names));

    EXPECT_TRUE(faker::testing::contains_any_of(
                    username_fixed_last_name, person::data::english_female_first_names)
        || faker::testing::contains_any_of(
            username_fixed_last_name, person::data::english_male_first_names));
    EXPECT_TRUE(username_fixed_last_name.find("Cieślar") != std::string::npos);

    EXPECT_TRUE(username_fixed.find("FixedFirstName") != std::string::npos);
    EXPECT_TRUE(username_fixed.find("FixedLastName") != std::string::npos);

    EXPECT_TRUE(faker::testing::contains_any_of(
                    username_with_non_ascii_chars, person::data::romanian_female_first_names)
        || faker::testing::contains_any_of(
            username_with_non_ascii_chars, person::data::romanian_male_first_names));
    EXPECT_TRUE(faker::testing::contains_any_of(
        username_with_non_ascii_chars, person::data::romanian_last_names));
}

TEST_F(InternetTest, should_generate_email)
{
    const auto email = internet::email();
    const auto email_fixed_first_name = internet::email("Tom");
    const auto email_fixed_last_name = internet::email(std::nullopt, "Howard");
    const auto email_fixed_name = internet::email("Cindy", "Young");
    const auto email_fixed_host = internet::email(std::nullopt, std::nullopt, "o2.pl");

    auto email_parts = utils::split(email, "@");
    EXPECT_EQ(email_parts.size(), 2u);
    EXPECT_TRUE(
        faker::testing::contains_any_of(email_parts[0], person::data::english_female_first_names)
        || faker::testing::contains_any_of(email_parts[0], person::data::english_male_first_names));
    EXPECT_TRUE(faker::testing::contains_any_of(email_parts[0], person::data::english_last_names));
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::email_hosts, email_parts[1]);

    auto email_fixed_first_name_parts = utils::split(email_fixed_first_name, "@");
    EXPECT_EQ(email_fixed_first_name_parts.size(), 2u);
    EXPECT_TRUE(email_fixed_first_name_parts[0].find("Tom") != std::string::npos);
    EXPECT_TRUE(faker::testing::contains_any_of(
        email_fixed_first_name_parts[0], person::data::english_last_names));
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::email_hosts, email_fixed_first_name_parts[1]);

    auto email_fixed_last_name_parts = utils::split(email_fixed_last_name, "@");
    EXPECT_EQ(email_fixed_last_name_parts.size(), 2u);
    EXPECT_TRUE(faker::testing::contains_any_of(
                    email_fixed_last_name_parts[0], person::data::english_male_first_names)
        || faker::testing::contains_any_of(
            email_fixed_last_name_parts[0], person::data::english_female_first_names));
    EXPECT_TRUE(email_fixed_last_name_parts[0].find("Howard") != std::string::npos);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::email_hosts, email_fixed_last_name_parts[1]);

    auto email_fixed_name_parts = utils::split(email_fixed_name, "@");
    EXPECT_EQ(email_fixed_name_parts.size(), 2u);
    EXPECT_TRUE(email_fixed_name_parts[0].find("Cindy") != std::string::npos);
    EXPECT_TRUE(email_fixed_name_parts[0].find("Young") != std::string::npos);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::email_hosts, email_fixed_name_parts[1]);

    auto email_fixed_host_parts = utils::split(email_fixed_host, "@");
    EXPECT_EQ(email_fixed_host_parts.size(), 2u);
    EXPECT_TRUE(faker::testing::contains_any_of(
                    email_fixed_host_parts[0], person::data::english_female_first_names)
        || faker::testing::contains_any_of(
            email_fixed_host_parts[0], person::data::english_male_first_names));
    EXPECT_TRUE(faker::testing::contains_any_of(
        email_fixed_host_parts[0], person::data::english_last_names));
    EXPECT_EQ(email_fixed_host_parts[1], "o2.pl");
}

TEST_F(InternetTest, should_generate_example_email)
{
    const auto email = internet::example_email();
    const auto email_fixed_first_name = internet::example_email("Barry");
    const auto email_fixed_last_name = internet::example_email(std::nullopt, "Wilkinson");
    const auto email_fixed_name = internet::example_email("Walter", "Brown");

    const auto email_parts = utils::split(email, "@");
    EXPECT_EQ(email_parts.size(), 2u);
    EXPECT_TRUE(
        faker::testing::contains_any_of(email_parts[0], person::data::english_female_first_names)
        || faker::testing::contains_any_of(email_parts[0], person::data::english_male_first_names));
    EXPECT_TRUE(faker::testing::contains_any_of(email_parts[0], person::data::english_last_names));
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::email_example_hosts, email_parts[1]);

    const auto email_fixed_first_name_parts = utils::split(email_fixed_first_name, "@");
    EXPECT_EQ(email_fixed_first_name_parts.size(), 2u);
    EXPECT_TRUE(email_fixed_first_name_parts[0].find("Barry") != std::string::npos);
    EXPECT_TRUE(faker::testing::contains_any_of(
        email_fixed_first_name_parts[0], person::data::english_last_names));
    FAKER_EXPECT_CONTAINER_CONTAINS(
        internet::data::email_example_hosts, email_fixed_first_name_parts[1]);

    const auto email_fixed_last_name_parts = utils::split(email_fixed_last_name, "@");
    EXPECT_EQ(email_fixed_last_name_parts.size(), 2u);
    EXPECT_TRUE(faker::testing::contains_any_of(
                    email_fixed_last_name_parts[0], person::data::english_male_first_names)
        || faker::testing::contains_any_of(
            email_fixed_last_name_parts[0], person::data::english_female_first_names));
    EXPECT_TRUE(email_fixed_last_name_parts[0].find("Wilkinson") != std::string::npos);
    FAKER_EXPECT_CONTAINER_CONTAINS(
        internet::data::email_example_hosts, email_fixed_last_name_parts[1]);

    const auto email_fixed_name_parts = utils::split(email_fixed_name, "@");
    EXPECT_EQ(email_fixed_name_parts.size(), 2u);
    EXPECT_TRUE(email_fixed_name_parts[0].find("Walter") != std::string::npos);
    EXPECT_TRUE(email_fixed_name_parts[0].find("Brown") != std::string::npos);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::email_example_hosts, email_fixed_name_parts[1]);
}

TEST_F(InternetTest, should_generate_password)
{
    const auto password = internet::password();
    const auto password_fixed_length = internet::password(25);

    EXPECT_EQ(password.size(), 15u);
    EXPECT_TRUE(contains_only_valid_password_chars(password));

    EXPECT_EQ(password_fixed_length.size(), 25u);
    EXPECT_TRUE(contains_only_valid_password_chars(password_fixed_length));
}

TEST_F(InternetTest, should_generate_emoji)
{
    const auto any_emoji = internet::emoji();
    const auto emoji_smiley = internet::emoji(internet::emoji_type::smiley);
    const auto emoji_body = internet::emoji(internet::emoji_type::body);
    const auto emoji_person = internet::emoji(internet::emoji_type::person);
    const auto emoji_nature = internet::emoji(internet::emoji_type::nature);
    const auto emoji_food = internet::emoji(internet::emoji_type::food);
    const auto emoji_travel = internet::emoji(internet::emoji_type::travel);
    const auto emoji_activity = internet::emoji(internet::emoji_type::activity);
    const auto emoji_object = internet::emoji(internet::emoji_type::object);
    const auto emoji_symbol = internet::emoji(internet::emoji_type::symbol);
    const auto emoji_flag = internet::emoji(internet::emoji_type::flag);

    EXPECT_TRUE(faker::testing::contains(internet::data::smiley_emojis, any_emoji)
        || faker::testing::contains(internet::data::body_emojis, any_emoji)
        || faker::testing::contains(internet::data::person_emojis, any_emoji)
        || faker::testing::contains(internet::data::nature_emojis, any_emoji)
        || faker::testing::contains(internet::data::food_emojis, any_emoji)
        || faker::testing::contains(internet::data::travel_emojis, any_emoji)
        || faker::testing::contains(internet::data::activity_emojis, any_emoji)
        || faker::testing::contains(internet::data::object_emojis, any_emoji)
        || faker::testing::contains(internet::data::symbol_emojis, any_emoji)
        || faker::testing::contains(internet::data::flag_emojis, any_emoji));
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::smiley_emojis, emoji_smiley);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::body_emojis, emoji_body);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::person_emojis, emoji_person);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::nature_emojis, emoji_nature);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::food_emojis, emoji_food);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::travel_emojis, emoji_travel);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::activity_emojis, emoji_activity);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::object_emojis, emoji_object);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::symbol_emojis, emoji_symbol);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::flag_emojis, emoji_flag);
}

TEST_F(InternetTest, should_generate_protocol)
{
    const auto protocol = internet::protocol();

    FAKER_EXPECT_CONTAINER_CONTAINS(web_protocols, protocol);
}

TEST_F(InternetTest, should_generate_http_method)
{
    const auto http_method = internet::http_method();

    FAKER_EXPECT_CONTAINER_CONTAINS(http_method_names, http_method);
}

TEST_F(InternetTest, should_generate_http_status_code)
{
    const auto any_status_code = internet::http_status_code();
    const auto code_informational
        = internet::http_status_code(internet::http_response_type::informational);
    const auto code_success = internet::http_status_code(internet::http_response_type::success);
    const auto code_redirect
        = internet::http_status_code(internet::http_response_type::redirection);
    const auto code_client_error
        = internet::http_status_code(internet::http_response_type::client_error);
    const auto code_server_error
        = internet::http_status_code(internet::http_response_type::server_error);

    EXPECT_TRUE(faker::testing::contains(http_status_codes_1xx, any_status_code)
        || faker::testing::contains(http_status_codes_2xx, any_status_code)
        || faker::testing::contains(http_status_codes_3xx, any_status_code)
        || faker::testing::contains(http_status_codes_4xx, any_status_code)
        || faker::testing::contains(http_status_codes_5xx, any_status_code));
    FAKER_EXPECT_CONTAINER_CONTAINS(http_status_codes_1xx, code_informational);
    FAKER_EXPECT_CONTAINER_CONTAINS(http_status_codes_2xx, code_success);
    FAKER_EXPECT_CONTAINER_CONTAINS(http_status_codes_3xx, code_redirect);
    FAKER_EXPECT_CONTAINER_CONTAINS(http_status_codes_4xx, code_client_error);
    FAKER_EXPECT_CONTAINER_CONTAINS(http_status_codes_5xx, code_server_error);
}

TEST_F(InternetTest, should_generate_http_request_header)
{
    const auto request_header = internet::http_request_header();

    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::http_request_headers, request_header);
}

TEST_F(InternetTest, should_generate_http_response_header)
{
    const auto response_header = internet::http_response_header();

    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::http_response_headers, response_header);
}

TEST_F(InternetTest, should_generate_http_media_type)
{
    const auto media_type = internet::http_media_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::http_media_types, media_type);
}

TEST_F(InternetTest, should_generate_ipv4)
{
    const auto ipv4_a = internet::ipv4(internet::ipv4_class::a);
    const auto ipv4_b = internet::ipv4(internet::ipv4_class::b);
    const auto ipv4_c = internet::ipv4(internet::ipv4_class::c);

    const auto ipv4_a_sectors = parse_ipv4_string(ipv4_a);
    EXPECT_EQ(ipv4_a_sectors[0], class_a_first_section);

    const auto ipv4_b_sectors = parse_ipv4_string(ipv4_b);
    EXPECT_EQ(ipv4_b_sectors[0], class_b_first_section);
    FAKER_EXPECT_BETWEEN(
        ipv4_b_sectors[1], class_b_second_section_lower_bound, class_b_second_section_upper_bound);

    const auto ipv4_c_sectors = parse_ipv4_string(ipv4_c);
    EXPECT_EQ(ipv4_c_sectors[0], class_c_first_section);
    EXPECT_EQ(ipv4_c_sectors[1], class_c_second_section);
}

TEST_F(InternetTest, should_generate_ipv4_with_mask)
{
    const std::array<unsigned, 4> sample_address = { 192, 168, 10, 12 };
    const std::array<unsigned, 4> generation_mask = { 255, 128, 0, 0 };

    const auto ipv4 = internet::ipv4(sample_address, generation_mask);

    const auto ipv4_sectors = parse_ipv4_string(ipv4);
    EXPECT_EQ(sample_address[0], ipv4_sectors[0]);
    EXPECT_TRUE((ipv4_sectors[1] & generation_mask[1]) == 0x00000080);
}

TEST_F(InternetTest, should_generate_ipv6)
{
    const auto ipv6 = internet::ipv6();

    const auto ipv6_parts = utils::split(ipv6, ":");
    EXPECT_EQ(ipv6_parts.size(), 8u);
    EXPECT_TRUE(faker::testing::all_of(ipv6_parts, [](auto part) { return part.size() == 4; }));
    EXPECT_TRUE(faker::testing::all_of(ipv6_parts, [](auto part) {
        return faker::testing::all_of(part,
            [](char ch) { return string::data::hex_lower_digits.find(ch) != std::string::npos; });
    }));
}

TEST_F(InternetTest, should_generate_mac_address)
{
    const auto mac = internet::mac();

    static const std::regex re_mac("([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})");

    EXPECT_TRUE(std::regex_match(mac, re_mac));
}

TEST_F(InternetTest, should_generate_domain_suffix)
{
    const auto domain_suffix = internet::domain_suffix();

    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::domain_suffixes, domain_suffix);
}

TEST_F(InternetTest, should_generate_domain_word)
{
    const auto domain_word = internet::domain_word();

    assert_valid_domain_word(domain_word);
}

TEST_F(InternetTest, shouldGenerateDomainName)
{
    const auto domain_name = internet::domain_name();

    const auto domain_name_parts = utils::split(domain_name, ".");
    assert_valid_domain_word(domain_name_parts[0]);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::domain_suffixes, domain_name_parts[1]);
}

TEST_F(InternetTest, shouldGenerateHttpsUrl)
{
    const auto https_url = internet::url();
    const auto http_url = internet::url(internet::web_protocol::http);

    const auto https_url_parts = utils::split(https_url, "://");
    EXPECT_EQ(https_url_parts[0], "https");

    const auto http_url_parts = utils::split(http_url, "://");
    EXPECT_EQ(http_url_parts[0], "http");

    const auto https_url_domain_name_parts = utils::split(https_url_parts[1], ".");
    assert_valid_domain_word(https_url_domain_name_parts[0]);
    FAKER_EXPECT_CONTAINER_CONTAINS(
        internet::data::domain_suffixes, https_url_domain_name_parts[1]);

    const auto http_url_domain_name_parts = utils::split(http_url_parts[1], ".");
    assert_valid_domain_word(http_url_domain_name_parts[0]);
    FAKER_EXPECT_CONTAINER_CONTAINS(internet::data::domain_suffixes, http_url_domain_name_parts[1]);
}

TEST_F(InternetTest, should_generate_port)
{
    const auto port = internet::port();

    FAKER_EXPECT_BETWEEN(port, 0u, 65535u);
}
