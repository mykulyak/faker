#include "../test_helpers.h"
#include <common/strings.h>
#include <faker/book.h>
#include <modules/book_data.h>

using namespace faker;

TEST(BookTest, should_generate_title)
{
    auto any_title = book::title();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::titles, any_title);
}

TEST(BookTest, should_generate_genre)
{
    auto any_genre = book::genre();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::genres, any_genre);
}

TEST(BookTest, should_generate_author)
{
    auto any_author = book::author();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::authors, any_author);
}

TEST(BookTest, should_generate_publisher)
{
    auto any_publisher = book::publisher();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::publishers, any_publisher);
}

TEST(BookTest, should_generate_isbn)
{
    auto any_isbn = book::isbn();

    EXPECT_EQ(any_isbn.size(), 17u);

    auto number_groups = utils::split(any_isbn, "-");
    EXPECT_EQ(number_groups[0].size(), 3u);
    EXPECT_EQ(number_groups[1].size(), 2u);
    EXPECT_EQ(number_groups[2].size(), 2u);
    EXPECT_EQ(number_groups[3].size(), 5u);
    EXPECT_EQ(number_groups[4].size(), 1u);
}

TEST(BookTest, should_generate_release_year)
{
    auto any_year = book::release_year();

    FAKER_EXPECT_BETWEEN(any_year, 1940u, 2024u);
}

TEST(BookTest, should_generate_translator)
{
    auto any_translator = book::translator();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::translators, any_translator);
}

TEST(BookTest, should_generate_format)
{
    auto any_format = book::format();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::book_formats, any_format);
}

TEST(BookTest, should_generate_page)
{
    auto any_page = book::page();

    FAKER_EXPECT_BETWEEN(any_page, 50u, 999u);
}

TEST(BookTest, should_generate_series)
{
    auto any_series = book::series();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::book_series, any_series);
}
