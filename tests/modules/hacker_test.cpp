#include "../test_helpers.h"
#include <faker/hacker.h>
#include <modules/hacker_data.h>

using namespace faker;

TEST(HackerTest, should_generate_abbreviation)
{
    auto abbreviation = hacker::abbreviation();

    FAKER_EXPECT_CONTAINER_CONTAINS(hacker::data::abbreviations, abbreviation);
}

TEST(HackerTest, should_generate_adjective)
{
    auto adjective = hacker::adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(hacker::data::adjectives, adjective);
}

TEST(HackerTest, should_generate_noun)
{
    auto noun = hacker::noun();

    FAKER_EXPECT_CONTAINER_CONTAINS(hacker::data::nouns, noun);
}

TEST(HackerTest, should_generate_verb)
{
    auto verb = hacker::verb();

    FAKER_EXPECT_CONTAINER_CONTAINS(hacker::data::verbs, verb);
}

TEST(HackerTest, should_generate_ingverb)
{
    auto ingverb = hacker::ingverb();

    FAKER_EXPECT_CONTAINER_CONTAINS(hacker::data::ingverbs, ingverb);
}

TEST(HackerTest, should_generate_phrase)
{
    auto phrase = hacker::phrase();

    auto has_adjective = faker::testing::any_of(hacker::data::adjectives,
        [&](auto item) { return phrase.find(item) != std::string::npos; });
    auto has_noun = faker::testing::any_of(
        hacker::data::nouns, [&](auto item) { return phrase.find(item) != std::string::npos; });
    auto has_verb = faker::testing::any_of(
        hacker::data::verbs, [&](auto item) { return phrase.find(item) != std::string::npos; });
    auto has_abbreviation = faker::testing::any_of(hacker::data::abbreviations,
        [&](auto item) { return phrase.find(item) != std::string::npos; });

    ASSERT_TRUE((has_adjective && has_noun && has_verb && has_abbreviation));
}
