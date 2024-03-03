#include "../test_helpers.h"
#include <faker/airline.h>
#include <faker/number.h>
#include <faker/string.h>
#include <modules/airline_data.h>

using namespace faker;

namespace {
bool contains_number_in_range(const std::string& str, int min, int max)
{
    for (int i = max; i >= min; --i) {
        if (str.find(std::to_string(i)) != std::string::npos) {
            return true;
        }
    }
    return false;
}
}

TEST(AirlineTest, should_generate_aircraft_type)
{
    auto aircraft_type = airline::aircraft_type_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::aircraft_types, aircraft_type);
}

TEST(AirlineTest, should_generate_airline)
{
    auto airline = airline::airline();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::airlines, airline);
}

TEST(AirlineTest, should_generate_airplane)
{
    auto airplane = airline::airplane();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::airplanes, airplane);
}

TEST(AirlineTest, should_generate_airport)
{
    auto airport = airline::airport();

    FAKER_EXPECT_CONTAINER_CONTAINS(airline::data::airports, airport);
}

TEST(AirlineTest, should_generate_record_locator)
{
    auto locator_without_numbers = airline::record_locator(false);
    auto locator_with_numbers = airline::record_locator(true);

    EXPECT_EQ(locator_without_numbers.size(), 6u);
    EXPECT_TRUE(
        faker::testing::all_of(locator_without_numbers, [](char c) { return std::isalpha(c); }));

    EXPECT_EQ(locator_with_numbers.size(), 6u);
    EXPECT_TRUE(
        faker::testing::all_of(locator_with_numbers, [](char c) { return std::isalnum(c); }));
}

TEST(AirlineTest, should_generate_regional_seat_number)
{
    auto seat_number = airline::seat(airline::aircraft_type::regional);

    FAKER_EXPECT_BETWEEN(seat_number.size(), 2u, 3u);

    EXPECT_TRUE(contains_number_in_range(seat_number, 1,
        airline::data::aircraft_type_max_rows.at(airline::aircraft_type::regional)));
    EXPECT_TRUE(faker::testing::contains(
        airline::data::aircraft_type_seat_letters.at(airline::aircraft_type::regional),
        seat_number.back()));
}

TEST(AirlineTest, should_generate_narrow_body_seat_number)
{
    auto seat_number = airline::seat(airline::aircraft_type::narrow_body);

    FAKER_EXPECT_BETWEEN(seat_number.size(), 2u, 3u);

    EXPECT_TRUE(contains_number_in_range(seat_number, 1,
        airline::data::aircraft_type_max_rows.at(airline::aircraft_type::narrow_body)));
    EXPECT_TRUE(faker::testing::contains(
        airline::data::aircraft_type_seat_letters.at(airline::aircraft_type::narrow_body),
        seat_number.back()));
}

TEST(AirlineTest, should_generate_wide_body_seat_number)
{
    auto seat_number = airline::seat(airline::aircraft_type::wide_body);

    FAKER_EXPECT_BETWEEN(seat_number.size(), 2u, 3u);

    EXPECT_TRUE(contains_number_in_range(seat_number, 1,
        airline::data::aircraft_type_max_rows.at(airline::aircraft_type::wide_body)));
    EXPECT_TRUE(faker::testing::contains(
        airline::data::aircraft_type_seat_letters.at(airline::aircraft_type::wide_body),
        seat_number.back()));
}

TEST(AirlineTest, should_generate_flight_number)
{
    auto flight_number = airline::flight_number();

    EXPECT_EQ(flight_number.size(), 4u);
    FAKER_EXPECT_BETWEEN(std::stoi(flight_number), 1000, 9999);
}

TEST(AirlineTest, should_generate_flight_number_with_leading_zero)
{
    size_t try_count = 0u;

    while (try_count <= 1000) { // 1e-46 chance of failing
        std::string flight_number = airline::flight_number(true, 4);
        if (flight_number.front() == '0') {
            break;
        }
    }

    EXPECT_TRUE(try_count < 1000);
}

TEST(AirlineTest, should_generate_flight_number_by_range)
{
    auto flight_number_with_variable_length = airline::flight_number_by_range(false, 1, 6);

    FAKER_EXPECT_BETWEEN(flight_number_with_variable_length.size(), 1u, 6u);
}
