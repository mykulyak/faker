#include "../test_helpers.h"
#include <faker/computer.h>
#include <modules/computer_data.h>

using namespace faker;

TEST(ComputerTest, should_generate_computer_type)
{
    auto any_type = computer::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::types, any_type);
}

TEST(ComputerTest, should_generate_manufacturer)
{
    auto any_manufacturer = computer::manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::manufacturers, any_manufacturer);
}

TEST(ComputerTest, should_generate_model)
{
    auto any_model = computer::model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::models, any_model);
}

TEST(ComputerTest, should_generate_cpu_manufacturer)
{
    auto any_cpu_anufacturer = computer::cpu_manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::cpu_manufacturers, any_cpu_anufacturer);
}

TEST(ComputerTest, should_generate_cpu_type)
{
    auto any_cpu_type = computer::cpu_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::cpu_types, any_cpu_type);
}

TEST(ComputerTest, should_generate_cpu_model)
{
    auto any_cpu_model = computer::cpu_model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::cpu_models, any_cpu_model);
}

TEST(ComputerTest, should_generate_gpu_manufacturer)
{
    auto any_gpu_anufacturer = computer::gpu_manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::gpu_manufacturers, any_gpu_anufacturer);
}

TEST(ComputerTest, should_generate_gpu_type)
{
    auto any_gpu_type = computer::gpu_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::gpu_types, any_gpu_type);
}

TEST(ComputerTest, should_generate_gpu_model)
{
    auto any_gpu_model = computer::gpu_model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::gpu_models, any_gpu_model);
}
