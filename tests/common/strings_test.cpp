#include "../test_helpers.h"
#include <common/strings.h>

using namespace faker;

TEST(StringHelperTest, should_split_string_by_space)
{
    const auto with_default_sep = utils::split("faker cxx open source");
    const auto with_custom_sep = utils::split("faker\ncxx\nopen\nsource", "\n");

    std::vector<std::string_view> expected { "faker", "cxx", "open", "source" };
    EXPECT_EQ(with_default_sep, expected);
    EXPECT_EQ(with_custom_sep, expected);
}

TEST(StringHelperTest, should_join_strings)
{
    const std::vector<std::string> input { "Join", "faker", "development!" };

    const auto with_default_separator = utils::join(input);
    const auto with_custom_separator = utils::join(input, "\n");

    EXPECT_EQ(with_default_separator, "Join faker development!");
    EXPECT_EQ(with_custom_separator, "Join\nfaker\ndevelopment!");
}

TEST(StringHelperTest, should_repeat_string)
{
    auto result = utils::repeat("hello ", 3);

    EXPECT_EQ(result, "hello hello hello ");
}

TEST(StringHelperTest, should_convert_string_to_lower_case)
{
    EXPECT_EQ(utils::to_lower("HeLlo!"), "hello!");
}

TEST(StringHelperTest, should_detect_punctuation)
{
    std::string punctuation = ".,;:!?";
    for (char c : punctuation) {
        EXPECT_TRUE(utils::is_punctuation(c));
    }

    std::string not_punctuation = "abc123";
    for (char c : not_punctuation) {
        EXPECT_FALSE(utils::is_punctuation(c));
    }
}

TEST(StringHelperTest, should_remove_punctuation)
{
    EXPECT_EQ(utils::remove_punctuation("Hello, World!"), "Hello World");
}
