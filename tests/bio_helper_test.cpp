#include "bio_helper.h"
#include "test_helpers.h"

TEST(BioHelperTest, checkFormatToken)
{
    EXPECT_TRUE(faker::testing::check_bio_format("influence Devotee"));
}
