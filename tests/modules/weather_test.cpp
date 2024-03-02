#include "../test_helpers.h"
#include <faker/weather.h>
#include <modules/weather_data.h>

using namespace faker;

TEST(WeatherTest, should_generate_temperature)
{
    auto temperature = weather::temperature();

    FAKER_EXPECT_BETWEEN(temperature.metric, 10, 30);
    FAKER_EXPECT_BETWEEN(temperature.imperial, 50, 90);
}

TEST(WeatherTest, should_generate_pressure)
{
    auto pressure = weather::pressure();

    FAKER_EXPECT_BETWEEN(pressure.metric, 100.0, 102.0);
    FAKER_EXPECT_BETWEEN(pressure.imperial, 14.5, 14.8);
}

TEST(WeatherTest, should_generate_visibility)
{
    auto visibility = weather::visibility();

    FAKER_EXPECT_BETWEEN(visibility.metric, 1, 10.0);
    FAKER_EXPECT_BETWEEN(visibility.imperial, 1.6, 16.1);
}

TEST(WeatherTest, should_generate_wind_speed)
{
    auto wind_speed = weather::wind_speed();

    FAKER_EXPECT_BETWEEN(wind_speed.metric, 0.1, 24.2);
    FAKER_EXPECT_BETWEEN(wind_speed.imperial, 0.1, 15.0);
}

TEST(WeatherTest, should_generate_uv_idex)
{
    auto uv_index = weather::uv_index();

    FAKER_EXPECT_BETWEEN(uv_index, 0, 11);
}

TEST(WeatherTest, should_generate_humidity)
{
    auto humidity = weather::humidity();

    FAKER_EXPECT_BETWEEN(humidity, 0, 100);
}

TEST(WeatherTest, should_generate_weather_description)
{
    auto weather_description = weather::description();

    FAKER_EXPECT_CONTAINER_CONTAINS(weather::data::weather_descriptions, weather_description);
}

TEST(WeatherTest, should_generate_cloud_cover)
{
    auto cloud_cover = weather::cloud_cover();

    FAKER_EXPECT_BETWEEN(cloud_cover, 0, 100);
}
