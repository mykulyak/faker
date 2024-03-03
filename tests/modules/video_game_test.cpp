#include "../test_helpers.h"
#include <faker/video_game.h>
#include <modules/video_game_data.h>

using namespace faker;

TEST(VideoGameTest, should_generate_game_title)
{
    auto game_title = video_game::title();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::video_game_names, game_title);
}

TEST(VideoGameTest, should_generate_genre)
{
    auto genre = video_game::genre();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::genres, genre);
}

TEST(VideoGameTest, should_generate_platform)
{
    auto platform = video_game::platform();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::platforms, platform);
}

TEST(VideoGameTest, should_generate_studio_name)
{
    auto studio_name = faker::video_game::studio_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(video_game::data::studio_names, studio_name);
}
