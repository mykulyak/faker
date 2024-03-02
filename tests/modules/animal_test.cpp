#include "../test_helpers.h"
#include <faker/animal.h>
#include <modules/animal_data.h>

using namespace faker;

TEST(AnimalTest, should_generate_bear)
{
    auto any_bear = animal::bear();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::bears, any_bear);
}

TEST(AnimalTest, should_generate_bird)
{
    auto any_bird = animal::bird();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::birds, any_bird);
}

TEST(AnimalTest, should_generate_cat)
{
    auto any_cat = animal::cat();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::cats, any_cat);
}

TEST(AnimalTest, should_generate_cetacean)
{
    auto any_cetacean = animal::cetacean();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::cetaceans, any_cetacean);
}

TEST(AnimalTest, should_generate_cow)
{
    auto any_cow = animal::cow();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::cows, any_cow);
}

TEST(AnimalTest, should_generate_crocodilia)
{
    auto any_crocodilia = animal::crocodilia();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::crocodilia, any_crocodilia);
}

TEST(AnimalTest, should_generate_dog)
{
    auto any_dog = animal::dog();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::dogs, any_dog);
}

TEST(AnimalTest, should_generate_fish)
{
    auto and_fish = animal::fish();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::fishes, and_fish);
}

TEST(AnimalTest, should_generate_horse)
{
    auto any_horse = animal::horse();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::horses, any_horse);
}

TEST(AnimalTest, should_generate_insect)
{
    auto any_insect = animal::insect();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::insects, any_insect);
}

TEST(AnimalTest, should_generate_lion)
{
    auto any_lion = animal::lion();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::lions, any_lion);
}

TEST(AnimalTest, should_generate_rabbit)
{
    auto any_rabbit = animal::rabbit();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::rabbits, any_rabbit);
}

TEST(AnimalTest, should_generate_rodent)
{
    auto any_rodent = animal::rodent();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::rodents, any_rodent);
}

TEST(AnimalTest, should_generate_snake)
{
    auto any_snake = animal::snake();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::snakes, any_snake);
}

TEST(AnimalTest, should_generate_type)
{
    auto any_type = animal::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::types, any_type);
}