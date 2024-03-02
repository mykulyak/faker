#include "../test_helpers.h"
#include <common/luhn_check.h>

using namespace faker;

TEST(LuhnCheckTest, should_do_luhn_check)
{
    std::string input = "6453-4876-8626-8995-3771";
    bool result = utils::luhn_check(input);
    EXPECT_TRUE(result); // Replace true with the expected result for the given input.
}

TEST(LuhnCheckValueTest, should_return_luhn_check_result)
{
    std::string input = "6453-4876-8626-8995-377L";
    int result = utils::luhn_check_value(input);
    EXPECT_EQ(result, 1); // Replace 1 with the expected result for the given input.
}
