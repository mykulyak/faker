#include "../json_helper.h"
#include "../test_helpers.h"

using namespace faker;

TEST(JsonHelperTest, should_parse_simple_json_string)
{
    const auto result
        = faker::testing::simple_json_parser("{\"Test1\":\"Hello\",\"Test2\":\"World!\"}");

    ASSERT_TRUE(result.find("Test1") != result.end());
    ASSERT_TRUE(result.find("Test2") != result.end());

    const auto& [key1, value1] = *result.find("Test1");
    const auto& [key2, value2] = *result.find("Test2");

    EXPECT_EQ(key1, "Test1");
    EXPECT_EQ(key2, "Test2");
    EXPECT_EQ(value1, "Hello");
    EXPECT_EQ(value2, "World!");
}
