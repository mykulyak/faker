#include "../test_helpers.h"
#include <common/string_helper.h>
#include <faker/image.h>
#include <modules/image_data.h>

using namespace faker;

TEST(ImageTest, shouldGenerateImageUrlDefault)
{
    const auto imageUrl = image::imageUrl();

    ASSERT_EQ(imageUrl, "https://loremflickr.com/640/480");
}

TEST(ImageTest, shouldGenerateImageUrl)
{
    const auto width = 800;
    const auto height = 600;

    const auto imageUrl = image::imageUrl(width, height);

    ASSERT_EQ(imageUrl, "https://loremflickr.com/800/600");
}

TEST(ImageTest, shouldGenerateImageUrlCategory)
{
    const auto width = 800;
    const auto height = 600;
    const ImageCategory category = ImageCategory::Fashion;

    const auto imageUrl = image::imageUrl(width, height, category);

    ASSERT_EQ(imageUrl, "https://loremflickr.com/800/600/fashion");
}

TEST(ImageTest, shouldGenerateGithubAvatarUrl)
{
    const auto githubAvatarUrl = image::githubAvatarUrl();

    const std::string expectedGithubAvatarPrefix = "https://avatars.githubusercontent.com/u/";

    const auto userNumber = std::stoi(githubAvatarUrl.substr(expectedGithubAvatarPrefix.size()));

    FAKER_EXPECT_STARTS_WITH(githubAvatarUrl, expectedGithubAvatarPrefix);
    ASSERT_TRUE(userNumber >= 0 && userNumber <= 100000000);
}

TEST(ImageTest, shouldGenerateDimensions)
{
    const auto dimensions = image::dimensions();

    std::vector<std::string> split_dimensions = StringHelper::split(dimensions, "x");

    auto width_dimension = std::stoi(split_dimensions[0]);
    ASSERT_TRUE(width_dimension >= 1 && width_dimension <= 32720);

    auto height_dimension = std::stoi(split_dimensions[1]);
    ASSERT_TRUE(height_dimension >= 1 && height_dimension <= 17280);
}

TEST(ImageTest, shouldGenerateType)
{
    const auto generatedType = image::type();

    FAKER_EXPECT_CONTAINS(imageTypes, generatedType);
}