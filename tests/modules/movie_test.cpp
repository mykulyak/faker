#include "../test_helpers.h"
#include <faker/movie.h>
#include <modules/movie_data.h>

using namespace faker;

TEST(MovieTest, should_generate_Genre)
{
    auto genre = movie::genre();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::genres, genre);
}

TEST(MovieTest, should_generate_movie_title)
{
    auto movie_title = movie::movie_title();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::movies, movie_title);
}

TEST(MovieTest, should_generate_tv_show)
{
    auto tv_show = movie::tv_show();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::tv_shows, tv_show);
}

TEST(MovieTest, should_generate_director)
{
    auto director = movie::director();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::directors, director);
}

TEST(MovieTest, should_generate_actor)
{
    auto actor = movie::actor();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::actors, actor);
}

TEST(MovieTest, should_generate_actress)
{
    auto generated_actress = movie::actress();

    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::actresses, generated_actress);
}
