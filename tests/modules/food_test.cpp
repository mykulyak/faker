#include "../test_helpers.h"
#include <faker/food.h>
#include <modules/food_data.h>

using namespace faker;

TEST(FoodTest, should_generate_alcoholic_beverage)
{
    auto alcoholic_beverage = food::alcoholic_beverage();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::alcoholic_beverages, alcoholic_beverage);
}

TEST(FoodTest, should_generate_dish_name)
{
    auto dish_name = food::dish_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::dish_names, dish_name);
}

TEST(FoodTest, should_generate_food_categories)
{
    auto food_category = food::category();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::food_categories, food_category);
}

TEST(FoodTest, should_generate_fruit)
{
    auto fruit = food::fruit();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::fruits, fruit);
}

TEST(FoodTest, should_generate_meat)
{
    auto meat = food::meat();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::meats, meat);
}

TEST(FoodTest, should_generate_milk_product)
{
    auto milk_product = food::milk_product();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::milk_products, milk_product);
}

TEST(FoodTest, should_generate_nonalcoholic_beverages)
{
    auto nonalcoholic_beverage = food::non_alcoholic_beverage();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::nonalcoholic_beverages, nonalcoholic_beverage);
}

TEST(FoodTest, should_generate_nut)
{
    auto nut = food::nut();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::nuts, nut);
}

TEST(FoodTest, should_generate_oil)
{
    auto oil = food::oil();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::oils, oil);
}

TEST(FoodTest, should_generate_seafood)
{
    auto seafood = food::seafood();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::seafoods, seafood);
}

TEST(FoodTest, should_generate_seed)
{
    auto seed = food::seed();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::seeds, seed);
}

TEST(FoodTest, should_generate_grain)
{
    auto grain = food::grain();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::grains, grain);
}

TEST(FoodTest, should_generate_sugar_product)
{
    auto sugar_product = food::sugar_product();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::sugar_products, sugar_product);
}

TEST(FoodTest, should_generate_vegetable)
{
    auto vegetable = food::vegetable();

    FAKER_EXPECT_CONTAINER_CONTAINS(food::data::vegetables, vegetable);
}
