#include "../test_helpers.h"
#include <faker/weather.h>
#include <modules/weather_data.h>

using namespace faker;

TEST(WeatherTest, shouldGenerateTemperature)
{
    auto generatedTemperature = weather::temperature();

    ASSERT_TRUE(generatedTemperature.metric >= 10 && generatedTemperature.metric <= 30);
    ASSERT_TRUE(generatedTemperature.imperial >= 50 && generatedTemperature.imperial <= 90);
}

TEST(WeatherTest, shouldGeneratePressure)
{
    auto generatedPressure = weather::pressure();

    ASSERT_TRUE(generatedPressure.metric >= 100.0 && generatedPressure.metric <= 102.0);
    ASSERT_TRUE(generatedPressure.imperial >= 14.5 && generatedPressure.imperial <= 14.8);
}

TEST(WeatherTest, shouldGenerateVisibility)
{
    auto generatedVisibility = weather::visibility();

    ASSERT_TRUE(generatedVisibility.metric >= 1 && generatedVisibility.metric <= 10.0);
    ASSERT_TRUE(generatedVisibility.imperial >= 1.6 && generatedVisibility.imperial <= 16.1);
}

TEST(WeatherTest, shouldGenerateWindSpeed)
{
    auto generatedWindSpeed = weather::windSpeed();

    ASSERT_TRUE(generatedWindSpeed.metric >= 0.1 && generatedWindSpeed.metric <= 24.2);
    ASSERT_TRUE(generatedWindSpeed.imperial >= 0.1 && generatedWindSpeed.imperial <= 15.0);
}

TEST(WeatherTest, shouldGenerateUvIndex)
{
    auto generatedUvIndex = weather::uvIndex();

    ASSERT_TRUE(generatedUvIndex >= 0 && generatedUvIndex <= 11);
}

TEST(WeatherTest, shouldGenerateHumidity)
{
    auto generatedHumidity = weather::humidity();

    ASSERT_TRUE(generatedHumidity >= 0 && generatedHumidity <= 100);
}

TEST(WeatherTest, shouldGenerateWeatherDescription)
{
    auto generatedWeatherDescription = weather::weatherDescription();

    FAKER_EXPECT_CONTAINS(weather::data::weatherDescriptions, generatedWeatherDescription);
}

TEST(WeatherTest, shouldGenerateWeatherCloudCover)
{
    auto generatedCloudCover = weather::cloudCover();

    ASSERT_TRUE(generatedCloudCover >= 0 && generatedCloudCover <= 100);
}