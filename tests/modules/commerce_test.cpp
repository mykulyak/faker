#include "../test_helpers.h"
#include <common/strings.h>
#include <faker/commerce.h>
#include <modules/commerce_data.h>
#include <modules/string_data.h>

using namespace faker;

namespace {
bool string_contains_only_digits(const std::string& str)
{
    return faker::testing::all_of(
        str, [](char ch) { return string::data::digits.find(ch) != std::string::npos; });
}
}

TEST(CommerceTest, should_generate_department)
{
    auto any_department = commerce::department();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::departments, any_department);
}

TEST(CommerceTest, should_generate_price)
{
    auto any_price = commerce::price(100, 10000);

    auto price_parts = utils::split(any_price, ".");
    EXPECT_EQ(price_parts.size(), 2);
    EXPECT_EQ(price_parts[1].size(), 2);

    FAKER_EXPECT_BETWEEN(std::stof(any_price), 100, 10000);
}

TEST(CommerceTest, should_generate_sku)
{
    auto sku_default_length = commerce::sku();
    auto sku_fixed_length = commerce::sku(8);

    EXPECT_EQ(sku_default_length.size(), 4);
    EXPECT_TRUE(string_contains_only_digits(sku_default_length));

    EXPECT_EQ(sku_fixed_length.size(), 8);
    EXPECT_TRUE(string_contains_only_digits(sku_fixed_length));
}

TEST(CommerceTest, should_generate_product_full_name)
{
    auto product_name = commerce::product_full_name();

    auto product_name_parts = utils::split(product_name, " ");
    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_adjectives, product_name_parts[0]);
    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_materials, product_name_parts[1]);
    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_names, product_name_parts[2]);
}

TEST(CommerceTest, should_generate_product_adjective)
{
    auto product_adjective = commerce::product_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_adjectives, product_adjective);
}

TEST(CommerceTest, should_generate_product_material)
{
    auto product_material = commerce::product_material();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_materials, product_material);
}

TEST(CommerceTest, should_generate_product_name)
{
    auto product_name = commerce::product_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_names, product_name);
}

TEST(CommerceTest, should_generate_ean13)
{
    auto any_ean13 = commerce::ean13();

    int sum = 0;
    for (size_t i = 0; i < 13; i++) {
        if (i % 2 == 0) {
            sum += (any_ean13[i] - '0');
        } else {
            sum += 3 * (any_ean13[i] - '0');
        }
    }

    EXPECT_EQ(any_ean13.size(), 13);
    EXPECT_TRUE(sum % 10 == 0);
}

TEST(CommerceTest, should_generate_ean8)
{
    auto ean8 = commerce::ean8();

    int sum = 0;
    for (size_t i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            sum += 3 * (ean8[i] - '0');
        } else {
            sum += (ean8[i] - '0');
        }
    }

    EXPECT_EQ(ean8.size(), 8);
    EXPECT_TRUE(sum % 10 == 0);
}

TEST(CommerceTest, should_generate_isbn13)
{
    auto isbn13 = commerce::isbn13();

    int sum = 0;
    for (size_t i = 0; i < 13; i++) {
        if (i % 2 == 0) {
            sum += (isbn13[i] - '0');
        } else {
            sum += 3 * (isbn13[i] - '0');
        }
    }

    EXPECT_EQ(isbn13.size(), 13);
    EXPECT_TRUE(sum % 10 == 0);
}

TEST(CommerceTest, should_generate_isbn10)
{
    auto isbn10 = commerce::isbn10();

    int sum = 0, weight = 10;
    if (isbn10[9] == 'X') {
        for (size_t i = 0; i < 9; i++) {
            sum += (isbn10[i] - '0') * weight;
            weight--;
        }
        sum += 10;
    } else {
        for (size_t i = 0; i < 10; i++) {
            sum += (isbn10[i] - '0') * weight;
            weight--;
        }
    }

    EXPECT_EQ(isbn10.size(), 10);
    EXPECT_TRUE(sum % 11 == 0);
}

TEST(CommerceTest, should_generate_product_id)
{
    auto product_id = commerce::product_id();

    EXPECT_EQ(product_id.length(), 10);
    EXPECT_TRUE(faker::testing::all_of(product_id, [](auto c) { return std::isalnum(c); }));
}

TEST(CommerceTest, should_generate_payment_type)
{
    auto payment_type = commerce::payment_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::payment_types, payment_type);
}

TEST(CommerceTest, should_generate_payment_provider)
{
    auto payment_provider = commerce::payment_provider();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::payment_providers, payment_provider);
}

TEST(CommerceTest, should_generate_product_description)
{
    auto product_description = commerce::product_description();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_descriptions, product_description);
}

TEST(CommerceTest, should_generate_product_category)
{
    auto product_category = commerce::product_category();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_category_names, product_category);
}

TEST(CommerceTest, should_generate_product_review)
{
    auto product_review = commerce::product_review();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::product_reviews, product_review);
}

TEST(CommerceTest, should_generate_product_rating)
{
    auto product_rating = commerce::product_rating();

    FAKER_EXPECT_BETWEEN(product_rating, 0.0, 5.0);
}

TEST(CommerceTest, should_generate_discount_type)
{
    auto discount_type = commerce::discount_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(commerce::data::discount_types, discount_type);
}

TEST(CommerceTest, should_generate_discount_code)
{
    auto discount_code = commerce::discount_code();

    FAKER_EXPECT_BETWEEN(discount_code.length(), commerce::data::min_discount_code_length,
        commerce::data::max_discount_code_length);

    EXPECT_TRUE(faker::testing::all_of(discount_code,
        [](char ch) { return string::data::ascii_upper_alphanum.find(ch) != std::string::npos; }));
}

TEST(CommerceTest, should_generate_discount_amount)
{
    auto discount_amount = commerce::discount_amount();

    FAKER_EXPECT_BETWEEN(
        discount_amount, commerce::data::min_discount_amount, commerce::data::max_discount_amount);
}

TEST(CommerceTest, should_generate_discount_percentage)
{
    auto discount_percentage = commerce::discount_percentage();

    FAKER_EXPECT_BETWEEN(discount_percentage, commerce::data::min_discount_percentage,
        commerce::data::max_discount_percentage);
}
