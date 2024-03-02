#include "../test_helpers.h"
#include <charconv>
#include <common/formatter.h>
#include <common/strings.h>
#include <faker/color.h>
#include <modules/color_data.h>
#include <modules/string_data.h>

using namespace faker;

namespace {
template <size_t N>
std::array<int, N> parse_color_components(const std::string& color_str, std::string_view sep = " ")
{
    auto values = utils::split(color_str, sep);

    if (values.size() != N) {
        throw std::runtime_error(utils::format(
            "Expected {} components, but got {} in '{}'", N, values.size(), color_str));
    }

    std::array<int, N> result;
    for (size_t i = 0; i < N; ++i) {
        std::from_chars(values[i].data(), values[i].data() + values[i].size(), result[i]);
    }
    return result;
}
}

TEST(ColorTest, should_generate_color_name)
{
    auto generatedColorName = color::name();

    FAKER_EXPECT_CONTAINER_CONTAINS(color::data::colors, generatedColorName);
}

TEST(ColorTest, should_generate_rgb)
{
    auto rgb = color::rgb();
    auto rgba = color::rgb(true);

    FAKER_EXPECT_STRING_STARTS_WITH(rgb, "rgb(");
    FAKER_EXPECT_STRING_ENDS_WITH(rgb, ")");
    FAKER_EXPECT_STRING_STARTS_WITH(rgba, "rgba(");
    FAKER_EXPECT_STRING_ENDS_WITH(rgba, ")");

    auto rgb_components = parse_color_components<3>(rgb.substr(4, rgb.size() - 1));
    FAKER_EXPECT_BETWEEN(rgb_components[0], 0, 255);
    FAKER_EXPECT_BETWEEN(rgb_components[1], 0, 255);
    FAKER_EXPECT_BETWEEN(rgb_components[2], 0, 255);

    auto rgba_components = parse_color_components<4>(rgba.substr(5, rgba.size() - 1));
    FAKER_EXPECT_BETWEEN(rgba_components[0], 0, 255);
    FAKER_EXPECT_BETWEEN(rgba_components[1], 0, 255);
    FAKER_EXPECT_BETWEEN(rgba_components[2], 0, 255);
    FAKER_EXPECT_BETWEEN(rgba_components[3], 0, 1);
}

TEST(ColorTest, should_generate_hex)
{
    auto hex = color::hex();
    auto hex_0x_upper = color::hex(hex_case_t::upper, hex_prefix_t::zero_x, true);

    EXPECT_EQ(hex.size(), 7);
    FAKER_EXPECT_STRING_STARTS_WITH(hex, "#");
    EXPECT_TRUE(faker::testing::all_of(std::string_view(hex).substr(1),
        [&](char ch) { return string::data::hex_lower_digits.find(ch) != std::string::npos; }));

    ASSERT_EQ(hex_0x_upper.size(), 10);
    FAKER_EXPECT_STRING_STARTS_WITH(hex_0x_upper, "0x");
    EXPECT_TRUE(faker::testing::all_of(std::string_view(hex_0x_upper).substr(2),
        [&](char ch) { return string::data::hex_upper_digits.find(ch) != std::string::npos; }));
}

TEST(ColorTest, should_generate_hsl)
{
    auto hsl = faker::color::hsl();
    auto hsla = faker::color::hsl(true);

    FAKER_EXPECT_STRING_STARTS_WITH(hsl, "hsl(");
    FAKER_EXPECT_STRING_ENDS_WITH(hsl, ")");
    FAKER_EXPECT_STRING_STARTS_WITH(hsla, "hsla(");
    FAKER_EXPECT_STRING_ENDS_WITH(hsla, ")");

    auto hsl_components = parse_color_components<3>(hsl.substr(4, hsl.size() - 1));
    FAKER_EXPECT_BETWEEN(hsl_components[0], 0, 360);
    FAKER_EXPECT_BETWEEN(hsl_components[1], 0, 100);
    FAKER_EXPECT_BETWEEN(hsl_components[2], 0, 100);

    auto hsla_components = parse_color_components<4>(hsla.substr(5, hsla.size() - 1));
    FAKER_EXPECT_BETWEEN(hsla_components[0], 0, 360);
    FAKER_EXPECT_BETWEEN(hsla_components[1], 0, 100);
    FAKER_EXPECT_BETWEEN(hsla_components[2], 0, 100);
    FAKER_EXPECT_BETWEEN(hsla_components[3], 0, 1);
}

TEST(ColorTest, should_generate_lch)
{
    auto lch = faker::color::lch();
    auto lcha = faker::color::lch(true);

    FAKER_EXPECT_STRING_STARTS_WITH(lch, "lch(");
    FAKER_EXPECT_STRING_ENDS_WITH(lch, ")");
    FAKER_EXPECT_STRING_STARTS_WITH(lcha, "lcha(");
    FAKER_EXPECT_STRING_ENDS_WITH(lcha, ")");

    auto lch_components = parse_color_components<3>(lch.substr(4, lch.size() - 1));
    FAKER_EXPECT_BETWEEN(lch_components[0], 0, 100);
    FAKER_EXPECT_BETWEEN(lch_components[1], 0, 100);
    FAKER_EXPECT_BETWEEN(lch_components[2], 0, 360);

    auto lcha_components = parse_color_components<4>(lcha.substr(5, lcha.size() - 1));
    FAKER_EXPECT_BETWEEN(lcha_components[0], 0, 100);
    FAKER_EXPECT_BETWEEN(lcha_components[1], 0, 100);
    FAKER_EXPECT_BETWEEN(lcha_components[2], 0, 360);
    FAKER_EXPECT_BETWEEN(lcha_components[3], 0, 1);
}

TEST(ColorTest, should_generate_cmyk)
{
    auto cmyk = faker::color::cmyk();

    FAKER_EXPECT_STRING_STARTS_WITH(cmyk, "cmyk(");
    FAKER_EXPECT_STRING_ENDS_WITH(cmyk, ")");

    auto cmyk_components = parse_color_components<4>(cmyk.substr(5, cmyk.size() - 1));
    FAKER_EXPECT_BETWEEN(cmyk_components[0], 0, 1);
    FAKER_EXPECT_BETWEEN(cmyk_components[1], 0, 1);
    FAKER_EXPECT_BETWEEN(cmyk_components[2], 0, 1);
    FAKER_EXPECT_BETWEEN(cmyk_components[3], 0, 1);
}

TEST(ColorTest, should_generate_lab)
{
    auto lab = faker::color::lab();

    FAKER_EXPECT_STRING_STARTS_WITH(lab, "lab(");
    FAKER_EXPECT_STRING_ENDS_WITH(lab, ")");

    auto lab_components = parse_color_components<3>(lab.substr(4, lab.size() - 1));
    FAKER_EXPECT_BETWEEN(lab_components[0], 0, 100);
    FAKER_EXPECT_BETWEEN(lab_components[1], -128, 128);
    FAKER_EXPECT_BETWEEN(lab_components[2], -128, 128);
}

TEST(ColorTest, should_generate_hsb)
{
    auto hsb = faker::color::hsb();

    FAKER_EXPECT_STRING_STARTS_WITH(hsb, "hsb(");
    FAKER_EXPECT_STRING_ENDS_WITH(hsb, ")");

    auto hsb_components = parse_color_components<3>(hsb.substr(4, hsb.size() - 1));
    FAKER_EXPECT_BETWEEN(hsb_components[0], 0, 360);
    FAKER_EXPECT_BETWEEN(hsb_components[1], 0, 100);
    FAKER_EXPECT_BETWEEN(hsb_components[2], 0, 100);
}

TEST(ColorTest, should_generate_hsv)
{
    auto hsv = faker::color::hsv();

    FAKER_EXPECT_STRING_STARTS_WITH(hsv, "hsv(");
    FAKER_EXPECT_STRING_ENDS_WITH(hsv, ")");

    auto hsv_components = parse_color_components<3>(hsv.substr(4, hsv.size() - 1));
    FAKER_EXPECT_BETWEEN(hsv_components[0], 0, 360);
    FAKER_EXPECT_BETWEEN(hsv_components[1], 0, 100);
    FAKER_EXPECT_BETWEEN(hsv_components[2], 0, 100);
}

TEST(ColorTest, should_generate_Yuv)
{
    auto yuv = faker::color::yuv();

    FAKER_EXPECT_STRING_STARTS_WITH(yuv, "yuv(");
    FAKER_EXPECT_STRING_ENDS_WITH(yuv, ")");

    auto yuv_components = parse_color_components<3>(yuv.substr(4, yuv.size() - 1));
    FAKER_EXPECT_BETWEEN(yuv_components[0], 0, 255);
    FAKER_EXPECT_BETWEEN(yuv_components[1], 0, 255);
    FAKER_EXPECT_BETWEEN(yuv_components[2], 0, 255);
}