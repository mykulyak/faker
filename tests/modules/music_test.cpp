#include "../test_helpers.h"
#include <faker/music.h>
#include <modules/music_data.h>

using namespace faker;

TEST(MusicTest, shouldGenerateArtist)
{
    auto generatedArtist = music::artist();

    FAKER_EXPECT_CONTAINS(music::data::artists, generatedArtist);
}

TEST(MusicTest, shouldGenerateGenre)
{
    auto generatedGenre = music::genre();

    FAKER_EXPECT_CONTAINS(music::data::genres, generatedGenre);
}

TEST(MusicTest, shouldGenerateSongName)
{
    auto generatedSongName = music::songName();

    FAKER_EXPECT_CONTAINS(music::data::songNames, generatedSongName);
}
