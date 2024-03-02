#include "../test_helpers.h"
#include <common/strings.h>
#include <faker/image.h>
#include <modules/image_data.h>

using namespace faker;

TEST(ImageTest, should_generate_image_url)
{
    auto url_with_defaults = image::image_url();
    auto url_with_dimensions = image::image_url(800, 600);
    auto url_with_dimentions_and_category
        = image::image_url(800, 600, image::image_category::fashion);

    EXPECT_EQ(url_with_defaults, "https://loremflickr.com/640/480");
    EXPECT_EQ(url_with_dimensions, "https://loremflickr.com/800/600");
    EXPECT_EQ(url_with_dimentions_and_category, "https://loremflickr.com/800/600/fashion");
}

TEST(ImageTest, should_generate_github_avatar_url)
{
    auto avatar_url = image::github_avatar_url();

    const std::string expected_prefix = "https://avatars.githubusercontent.com/u/";
    FAKER_EXPECT_STRING_STARTS_WITH(avatar_url, expected_prefix);
    FAKER_EXPECT_BETWEEN(std::stoi(avatar_url.substr(expected_prefix.size())), 0, 100000000);
}

TEST(ImageTest, should_generate_dimensions)
{
    auto dimension_parts = utils::split(image::dimensions(), "x");

    FAKER_EXPECT_BETWEEN(utils::to_int(dimension_parts[0]), 1, 32720);
    FAKER_EXPECT_BETWEEN(utils::to_int(dimension_parts[1]), 1, 17280);
}

TEST(ImageTest, should_generate_type)
{
    auto type = image::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(image::data::image_types, type);
}