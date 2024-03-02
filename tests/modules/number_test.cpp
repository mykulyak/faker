#include "../test_helpers.h"
#include <faker/number.h>

using namespace faker;

TEST(NumberTest, should_generate_integer)
{
    const int fixed_int = number::integer(2, 2);
    const int int_with_min_max_limits = number::integer(2, 10);
    const int int_with_max_limit = number::integer(10);

    EXPECT_EQ(fixed_int, 2);
    FAKER_EXPECT_BETWEEN(int_with_min_max_limits, 2, 10);
    FAKER_EXPECT_BETWEEN(int_with_max_limit, 0, 10);
}

TEST(NumberTest, should_generate_floats)
{
    const auto fixed_float = number::decimal(2.f, 2.f);
    const auto float_with_min_max_limits = number::decimal(2.f, 10.f);
    const auto float_with_max_limit = number::decimal(0.1f);

    EXPECT_NEAR(fixed_float, 2.f, 1e-6f);
    FAKER_EXPECT_BETWEEN(float_with_min_max_limits, 2.f, 10.f);
    FAKER_EXPECT_BETWEEN(float_with_max_limit, 0.f, 0.1f);
}

TEST(NumberTest, should_throw_on_invalid_range)
{
    EXPECT_THROW(number::integer(10, 2), std::invalid_argument);
    EXPECT_THROW(number::decimal(10.f, 2.f), std::invalid_argument);
}

TEST(NumberTest, should_generate_hex_number)
{
    auto result = number::hex();
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(std::isxdigit(result[0]));

    result = number::hex(100, 255);
    EXPECT_EQ(result.size(), 2);
    EXPECT_TRUE(std::isxdigit(result[0]));
    EXPECT_TRUE(std::isxdigit(result[1]));

    result = number::hex(10, 15);
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(std::isxdigit(result[0]));

    result = number::hex(30, 40);
    EXPECT_EQ(result.size(), 2);
    EXPECT_TRUE(std::isxdigit(result[0]));
    EXPECT_TRUE(std::isxdigit(result[1]));
}
