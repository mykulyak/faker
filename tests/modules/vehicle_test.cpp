#include "../test_helpers.h"
#include <faker/vehicle.h>
#include <modules/vehicle_data.h>
#include <regex>

using namespace faker;

TEST(VehicleTest, should_generate_bicycle)
{
    auto bicycle = vehicle::bicycle();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::bicycle_types, bicycle);
}

TEST(VehicleTest, should_generate_color)
{
    auto color = vehicle::color();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::vehicle_colors, color);
}

TEST(VehicleTest, should_generate_fuel)
{
    auto fuel = vehicle::fuel();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::fuel_types, fuel);
}

TEST(VehicleTest, should_generate_manufacturer)
{
    auto manufacturer = vehicle::manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::manufacturers, manufacturer);
}

TEST(VehicleTest, should_generate_model)
{
    auto model = vehicle::model();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::models, model);
}

TEST(VehicleTest, should_generate_type)
{
    auto vehicle_type = vehicle::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::vehicle_types, vehicle_type);
}

TEST(VehicleTest, should_generate_vehicle)
{
    auto vehicle = vehicle::vehicle();

    ASSERT_TRUE(faker::testing::any_of(vehicle::data::manufacturers, [vehicle](auto manufacturer) {
        return faker::testing::starts_with(vehicle, manufacturer);
    }));

    ASSERT_TRUE(faker::testing::any_of(vehicle::data::models,
        [vehicle](auto model) { return faker::testing::ends_with(vehicle, model); }));
}

TEST(VehicleTest, should_generate_vin)
{
    auto vin = vehicle::vin();

    std::regex vin_regex("[A-HJ-NPR-Z0-9]{10}[A-HJ-NPR-Z0-9]{1}[A-HJ-NPR-Z0-9]{1}[0-9]{5}");

    EXPECT_TRUE(std::regex_match(vin, vin_regex));
}

TEST(VehicleTest, should_generate_vrm)
{
    auto vrm = vehicle::vrm();

    std::regex vrm_regex("[A-Z]{2}[0-9]{2}[A-Z]{3}");

    EXPECT_TRUE(std::regex_match(vrm, vrm_regex));
}
