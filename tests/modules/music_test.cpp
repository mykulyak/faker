#include "../test_helpers.h"
#include <faker/music.h>
#include <modules/music_data.h>

using namespace faker;

TEST(MusicTest, should_generate_artist)
{
    auto artist = music::artist();

    FAKER_EXPECT_CONTAINER_CONTAINS(music::data::artists, artist);
}

TEST(MusicTest, should_generate_genre)
{
    auto genre = music::genre();

    FAKER_EXPECT_CONTAINER_CONTAINS(music::data::genres, genre);
}

TEST(MusicTest, should_generate_song_name)
{
    auto song_name = music::song_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(music::data::song_names, song_name);
}
