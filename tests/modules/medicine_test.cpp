#include "../test_helpers.h"
#include <faker/medicine.h>
#include <modules/medicine_data.h>

using namespace faker;

TEST(MedicineTest, should_generate_medical_condition)
{
    auto medical_condition = medicine::condition();

    FAKER_EXPECT_CONTAINER_CONTAINS(medicine::data::medical_conditions, medical_condition);
}

TEST(MedicineTest, should_generate_medical_test)
{
    auto medical_test = medicine::medical_test();

    FAKER_EXPECT_CONTAINER_CONTAINS(medicine::data::medical_tests, medical_test);
}

TEST(MedicineTest, should_generate_specialty)
{
    auto specialty = medicine::specialty();

    FAKER_EXPECT_CONTAINER_CONTAINS(medicine::data::specialties, specialty);
}
