#include "weather_data.h"

namespace faker::weather::data {
const std::array<std::string_view, 16> weather_descriptions = {
    "clear sky",
    "few clouds",
    "scattered clouds",
    "broken clouds",
    "shower rain",
    "rainy",
    "thunderstorm",
    "snowy",
    "misty",
    "smoky",
    "haze",
    "sunny",
    "cloudy",
    "windy",
    "dark",
    "foggy",
};
}
