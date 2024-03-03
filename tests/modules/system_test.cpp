#include "../test_helpers.h"
#include <algorithm>
#include <faker/system.h>
#include <modules/system_data.h>
#include <regex>
#include <stdexcept>
#include <unordered_set>

using namespace faker;

namespace {
bool is_valid_cron_expr(const std::string& value)
{
    const std::regex re_cron_expr(
        R"((\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)( (\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)){4,5})");

    return std::regex_match(value, re_cron_expr);
}
}

TEST(SystemTest, should_generate_filename)
{
    auto filename_fixed_ext_count = system::filename({ 3u, { 1u, 1u } });
    EXPECT_FALSE(filename_fixed_ext_count.empty());
    // some mime types contain '.' in them, hence >=
    EXPECT_GE(std::count(filename_fixed_ext_count.begin(), filename_fixed_ext_count.end(), '.'), 3);

    auto filename_variable_ext_count = system::filename({ 1, { 1, 3 } });
    EXPECT_FALSE(filename_variable_ext_count.empty());
    // some mime types contain '.' in them, hence >=
    EXPECT_GE(
        std::count(filename_variable_ext_count.begin(), filename_variable_ext_count.end(), '.'), 1);
}

TEST(SystemTest, should_generate_file_extension)
{
    std::vector<std::string_view> all_image_exts;
    std::vector<std::string_view> all_audio_exts;
    std::vector<std::string_view> all_video_exts;
    std::vector<std::string_view> all_text_exts;
    std::vector<std::string_view> all_application_exts;
    for (const auto& mime_type : system::data::mime_types) {
        size_t pos = mime_type.find_first_of('/');
        auto category = mime_type.substr(0, pos);
        if (category == "image") {
            all_image_exts.push_back(mime_type.substr(pos + 1));
        } else if (category == "audio") {
            all_audio_exts.push_back(mime_type.substr(pos + 1));
        } else if (category == "video") {
            all_video_exts.push_back(mime_type.substr(pos + 1));
        } else if (category == "text") {
            all_text_exts.push_back(mime_type.substr(pos + 1));
        } else if (category == "application") {
            all_application_exts.push_back(mime_type.substr(pos + 1));
        }
    }

    auto ext_any_type = system::file_ext();
    auto ext_image = system::file_ext(system::file_type_t::image);
    auto ext_audio = system::file_ext(system::file_type_t::audio);
    auto ext_video = system::file_ext(system::file_type_t::video);
    auto ext_text = system::file_ext(system::file_type_t::text);
    auto ext_application = system::file_ext(system::file_type_t::application);

    EXPECT_FALSE(ext_any_type.empty());
    FAKER_EXPECT_CONTAINER_CONTAINS(all_image_exts, ext_image);
    FAKER_EXPECT_CONTAINER_CONTAINS(all_audio_exts, ext_audio);
    FAKER_EXPECT_CONTAINER_CONTAINS(all_video_exts, ext_video);
    FAKER_EXPECT_CONTAINER_CONTAINS(all_text_exts, ext_text);
    FAKER_EXPECT_CONTAINER_CONTAINS(all_application_exts, ext_application);
}

TEST(SystemTest, should_generate_common_filename)
{
    auto filename_with_any_ext = system::common_filename();
    auto filename_with_fixed_ext = system::common_filename("txt");

    auto get_last_file_ext
        = [](const std::string& fname) { return fname.substr(fname.find_last_of('.') + 1); };

    EXPECT_FALSE(get_last_file_ext(filename_with_any_ext).empty());
    EXPECT_EQ(get_last_file_ext(filename_with_fixed_ext), "txt");
}

TEST(SystemTest, should_generate_mime_type)
{
    auto mime_type = system::mime_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(system::data::mime_types, mime_type);
}

TEST(SystemTest, should_generate_common_file_type)
{
    auto file_type = system::common_file_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(system::data::common_file_types, file_type);
}

TEST(SystemTest, should_generate_file_type)
{
    std::unordered_set<std::string_view> all_file_types;
    for (auto mime_type : system::data::mime_types) {
        size_t pos = mime_type.find('/');
        if (pos != std::string::npos) {
            auto type = mime_type.substr(0, pos);
            all_file_types.insert(type);
        }
    }

    auto file_type = system::file_type();

    EXPECT_TRUE(all_file_types.find(file_type) != all_file_types.end());
}

TEST(SystemTest, should_generate_file_path)
{
    auto path = system::file_path();

    EXPECT_FALSE(path.empty());
}

TEST(SystemTest, should_generate_semver)
{
    auto semver = system::semver();

    EXPECT_TRUE(std::regex_match(semver, std::regex("\\d+\\.\\d+\\.\\d+")));
}

TEST(SystemTest, NetworkInterfaceMethodTest)
{
    system::NetworkInterfaceOptions options_fixed_type;
    options_fixed_type.interfaceType = "wl";
    system::NetworkInterfaceOptions options_fixed_schema;
    options_fixed_schema.interfaceSchema = "mac";
    system::NetworkInterfaceOptions options_type_and_schema;
    options_type_and_schema.interfaceType = "en";
    options_type_and_schema.interfaceSchema = "pci";

    auto result_any = system::network_interface();
    auto result_fixed_type = system::network_interface(options_fixed_type);
    auto result_fixed_schema = system::network_interface(options_fixed_schema);
    auto result_fixed_type_and_schema = system::network_interface(options_type_and_schema);

    EXPECT_FALSE(result_any.empty());
    EXPECT_FALSE(result_fixed_type.empty());
    EXPECT_EQ(result_fixed_schema.size(), 15u);
    EXPECT_FALSE(result_fixed_type_and_schema.empty());
}

TEST(SystemTest, should_generate_cron_with_default_options)
{
    auto expr = system::cron();

    EXPECT_TRUE(is_valid_cron_expr(expr));
}

TEST(SystemTest, should_generate_cron_with_yaer_option)
{
    auto expr = system::cron(system::cron_options_t::include_year);

    EXPECT_TRUE(is_valid_cron_expr(expr));

    auto last_sep_pos = expr.find_last_of(' ');
    ASSERT_NE(last_sep_pos, std::string::npos);

    auto year_part_str = expr.substr(last_sep_pos + 1);
    if (year_part_str != "*") {
        auto year = std::stoi(year_part_str);
        FAKER_EXPECT_BETWEEN(year, 1970, 2099);
    }
}

TEST(SystemTest, should_generate_cron_with_non_standard_option)
{
    auto expr = system::cron(system::cron_options_t::include_non_standard);

    EXPECT_TRUE(faker::testing::contains(system::data::non_standard_cron_expressions, expr)
        || is_valid_cron_expr(expr));
}
