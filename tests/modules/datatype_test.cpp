#include "../test_helpers.h"
#include <array>
#include <faker/datatype.h>

using namespace faker;

TEST(DatatypeTest, should_generate_boolean)
{
    static const std::array<bool, 2> boolean_values { false, true };

    bool bool_0 = datatype::boolean(0.0);
    bool bool_0_3 = datatype::boolean(0.3);
    auto bool_0_5 = datatype::boolean();
    bool bool_0_8 = datatype::boolean(0.8);
    bool bool_1 = datatype::boolean(1.0);

    EXPECT_FALSE(bool_0);
    FAKER_EXPECT_CONTAINER_CONTAINS(boolean_values, bool_0_3);
    FAKER_EXPECT_CONTAINER_CONTAINS(boolean_values, bool_0_5);
    FAKER_EXPECT_CONTAINER_CONTAINS(boolean_values, bool_0_8);
    EXPECT_TRUE(bool_1);
}
