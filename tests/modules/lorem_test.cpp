#include "../test_helpers.h"
#include <algorithm>
#include <common/strings.h>
#include <faker/lorem.h>
#include <modules/lorem_data.h>

using namespace faker;

namespace {
template <typename ContainerT> bool contains_only_valid_words(const ContainerT& container)
{
    return faker::testing::all_of(container, [](const auto& word) {
        return faker::testing::contains(lorem::data::lorem_words, utils::to_lower(word));
    });
}
}

TEST(LoremTest, should_generate_word)
{
    auto word = lorem::word();

    FAKER_EXPECT_CONTAINER_CONTAINS(lorem::data::lorem_words, word);
}

TEST(LoremTest, should_generate_words)
{
    auto words = lorem::words(5);

    auto word_list = utils::split(words, " ");
    EXPECT_EQ(word_list.size(), 5);
    EXPECT_TRUE(contains_only_valid_words(word_list));
}

TEST(LoremTest, should_generate_sentence)
{
    const auto sentence = lorem::sentence();

    EXPECT_TRUE(std::isupper(sentence[0]));
    FAKER_EXPECT_STRING_ENDS_WITH(sentence, ".");

    const auto word_list = utils::split(sentence.substr(0, sentence.size() - 1), " ");
    FAKER_EXPECT_BETWEEN(word_list.size(), 3, 10);
    EXPECT_TRUE(contains_only_valid_words(word_list));
}

TEST(LoremTest, should_generate_sentences)
{
    const auto sentences = lorem::sentences();

    const auto sentence_list = utils::split(sentences, ". ");

    for (auto sentence : sentence_list) {
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        EXPECT_TRUE(std::isupper(sentence[0]));

        const auto word_list = utils::split(sentence, " ");
        FAKER_EXPECT_BETWEEN(word_list.size(), 3, 10);
        EXPECT_TRUE(contains_only_valid_words(word_list));
    }
}

TEST(LoremTest, should_generate_slug)
{
    const auto slug = lorem::slug(3);

    const auto word_list = utils::split(slug, "-");
    EXPECT_EQ(word_list.size(), 3);
    EXPECT_TRUE(contains_only_valid_words(word_list));
}

TEST(LoremTest, should_generate_paragraph)
{
    const auto paragraph = lorem::paragraph();

    const auto sentence_list = utils::split(paragraph, ". ");

    for (auto sentence : sentence_list) {
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        EXPECT_TRUE(std::isupper(sentence[0]));

        const auto word_list = utils::split(sentence, " ");
        FAKER_EXPECT_BETWEEN(word_list.size(), 3, 10);
        EXPECT_TRUE(contains_only_valid_words(word_list));
    }
}

TEST(LoremTest, should_generate_paragraphs)
{
    const auto paragraphs = lorem::paragraphs();

    const auto paragraph_list = utils::split(paragraphs, "\n");

    for (const auto& paragraph : paragraph_list) {
        const auto sentence_list = utils::split(paragraph, ". ");

        for (auto sentence : sentence_list) {
            sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

            EXPECT_TRUE(std::isupper(sentence[0]));

            const auto word_list = utils::split(sentence, " ");
            FAKER_EXPECT_BETWEEN(word_list.size(), 3, 10);
            EXPECT_TRUE(contains_only_valid_words(word_list));
        }
    }
}
