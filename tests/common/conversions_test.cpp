#include "../test_helpers.h"
#include <common/conversions.h>

using namespace faker;

TEST(WeatherHelperTest, should_convert_celsius_to_fahrenheit)
{
    EXPECT_EQ(utils::celsius_to_fahrenheit(-40.0), -40.0);
    EXPECT_EQ(utils::celsius_to_fahrenheit(10.0), 50.0);
}

TEST(WeatherHelperTest, should_convert_kpa_to_psi)
{
    EXPECT_EQ(utils::kpa_to_psi(100.0), 14.503773773375);
}

TEST(WeatherHelperTest, should_convert_miles_to_kilometers)
{
    EXPECT_EQ(utils::mile_to_km(10.0), 16.09344);
}
