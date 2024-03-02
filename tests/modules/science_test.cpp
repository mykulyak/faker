#include "../test_helpers.h"
#include <faker/science.h>
#include <modules/science_data.h>

using namespace faker;

TEST(ScienceTest, should_generate_chem_element)
{
    auto chemical_element = science::chemical_element();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::chemical_elements, chemical_element);
}

TEST(ScienceTest, should_generate_any_unit)
{
    auto unit = science::unit();

    EXPECT_TRUE(faker::testing::contains(science::data::distance_units, unit)
        || faker::testing::contains(science::data::mass_units, unit)
        || faker::testing::contains(science::data::time_units, unit)
        || faker::testing::contains(science::data::current_units, unit)
        || faker::testing::contains(science::data::temperature_units, unit));
}

TEST(ScienceTest, should_generate_distance_unit)
{
    auto unit = science::distance_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::distance_units, unit);
}

TEST(ScienceTest, should_generate_mass_unit)
{
    auto unit = science::mass_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::mass_units, unit);
}

TEST(ScienceTest, should_generate_time_unit)
{
    auto unit = science::time_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::time_units, unit);
}

TEST(ScienceTest, should_generate_temperature_unit)
{
    auto unit = science::temperature_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::temperature_units, unit);
}

TEST(ScienceTest, should_generate_current_unit)
{
    auto unit = science::current_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::current_units, unit);
}
