#include "../test_helpers.h"
#include <faker/sport.h>
#include <modules/sport_data.h>

using namespace faker;

TEST(SportTest, should_generate_sport)
{
    auto sport = sport::sport();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::sport_names, sport);
}

TEST(SportTest, should_generate_soccer_team)
{
    auto team_name = sport::soccer_team();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::soccer_teams, team_name);
}

TEST(SportTest, should_generate_sport_event)
{
    auto sport_event = sport::sport_event();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::sport_events, sport_event);
}

TEST(SportTest, should_generate_male_athlete)
{
    auto athlete = sport::male_athlete();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::male_athletes, athlete);
}

TEST(SportTest, should_generate_female_athlete)
{
    auto athlete = sport::female_athlete();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::female_athletes, athlete);
}
