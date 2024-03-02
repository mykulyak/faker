#include "../test_helpers.h"
#include <faker/database.h>
#include <modules/database_data.h>
#include <modules/string_data.h>

using namespace faker;

TEST(DatabaseTest, should_generate_column_name)
{
    auto column_name = database::column_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::column_names, column_name);
}

TEST(DatabaseTest, should_generate_column_type)
{
    auto column_type = database::column_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::column_types, column_type);
}

TEST(DatabaseTest, should_generate_engine)
{
    auto engine = database::engine();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::engines, engine);
}

TEST(DatabaseTest, should_generate_collation)
{
    auto collation = database::collation();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::collations, collation);
}

TEST(DatabaseTest, should_generate_mongodb_object_id)
{
    auto object_id = database::mongodb_object_id();

    EXPECT_EQ(object_id.size(), 24);
    EXPECT_TRUE(faker::testing::all_of(object_id,
        [](char ch) { return string::data::hex_lower_digits.find(ch) != std::string::npos; }));
}
