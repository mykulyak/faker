#include "../test_helpers.h"
#include <algorithm>
#include <common/strings.h>
#include <faker/word.h>
#include <modules/word_data.h>

using namespace faker;

namespace {
bool is_valid_word(std::string_view word)
{
    return faker::testing::contains(word::data::adjectives, word)
        || faker::testing::contains(word::data::adverbs, word)
        || faker::testing::contains(word::data::conjunctions, word)
        || faker::testing::contains(word::data::interjections, word)
        || faker::testing::contains(word::data::nouns, word)
        || faker::testing::contains(word::data::prepositions, word)
        || faker::testing::contains(word::data::verbs, word);
}
}

TEST(WordTest, should_generate_adjective)
{
    auto adjective_any_length = word::adjective();
    auto adjective_fixed_length = word::adjective(5);
    auto adjective_non_existent_length = word::adjective(100);

    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::adjectives, adjective_any_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::adjectives, adjective_fixed_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::adjectives, adjective_non_existent_length);
}

TEST(WordTest, should_generate_adverb)
{
    auto adverb_any_length = word::adverb();
    auto adverb_fixed_length = word::adverb(5);
    auto adverb_non_existent_length = word::adverb(100);

    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::adverbs, adverb_any_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::adverbs, adverb_fixed_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::adverbs, adverb_non_existent_length);
}

TEST(WordTest, should_generate_conjunction)
{
    auto conjunction_any_length = word::conjunction();
    auto conjunction_fixed_length = word::conjunction(5);
    auto conjunction_non_existent_length = word::conjunction(100);

    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::conjunctions, conjunction_any_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::conjunctions, conjunction_fixed_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::conjunctions, conjunction_non_existent_length);
}

TEST(WordTest, should_generate_interjection)
{
    auto interjection_any_length = word::interjection();
    auto interjection_fixed_length = word::interjection(5);
    auto interjection_non_existent_length = word::interjection(100);

    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::interjections, interjection_any_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::interjections, interjection_fixed_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::interjections, interjection_non_existent_length);
}

TEST(WordTest, should_generate_noun)
{
    auto noun_any_length = word::noun();
    auto noun_fixed_length = word::noun(5);
    auto noun_non_existent_length = word::noun(100);

    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::nouns, noun_any_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::nouns, noun_fixed_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::nouns, noun_non_existent_length);
}

TEST(WordTest, should_generate_preposition)
{
    auto preposition_any_length = word::preposition();
    auto preposition_fixed_length = word::preposition(5);
    auto preposition_non_existent_length = word::preposition(100);

    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::prepositions, preposition_any_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::prepositions, preposition_fixed_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::prepositions, preposition_non_existent_length);
}

TEST(WordTest, should_generate_verb)
{
    auto verb_any_length = word::verb();
    auto verb_fixed_length = word::verb(5);
    auto verb_non_existent_length = word::verb(100);

    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::verbs, verb_any_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::verbs, verb_fixed_length);
    FAKER_EXPECT_CONTAINER_CONTAINS(word::data::verbs, verb_non_existent_length);
}

TEST(WordTest, should_generate_sample)
{
    auto sample_any_length = word::sample();
    auto sample_fixed_length = word::sample(5);
    auto sample_non_existent_length = word::sample(100);

    EXPECT_TRUE(is_valid_word(sample_any_length));
    EXPECT_TRUE(is_valid_word(sample_fixed_length));
    EXPECT_TRUE(is_valid_word(sample_non_existent_length));
}

TEST(WordTest, should_generate_words)
{
    auto words = word::words(5);

    auto split_words = utils::split(words, " ");
    EXPECT_TRUE(faker::testing::all_of(split_words, is_valid_word));
}
