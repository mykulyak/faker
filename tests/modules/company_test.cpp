#include "../test_helpers.h"
#include <common/strings.h>
#include <faker/company.h>
#include <modules/company_data.h>
#include <modules/person_data.h>

using namespace faker;

TEST(CompanyTest, should_generate_company_name)
{
    auto company_name = company::name();

    auto name_parts = utils::split(company_name, " ");
    if (name_parts.size() == 2) {
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::english_last_names, name_parts[0]);
        FAKER_EXPECT_CONTAINER_CONTAINS(company::data::company_suffixes, name_parts[1]);
    } else if (name_parts.size() == 3) {
        EXPECT_TRUE(faker::testing::contains(person::data::english_male_first_names, name_parts[0])
            || faker::testing::contains(person::data::english_female_first_names, name_parts[0]));
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::english_last_names, name_parts[1]);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, name_parts[2]);
    } else if (name_parts.size() == 4) {
        EXPECT_TRUE(faker::testing::contains(person::data::english_male_first_names, name_parts[0])
            || faker::testing::contains(person::data::english_female_first_names, name_parts[0]));
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::english_last_names, name_parts[1]);
        FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, name_parts[2]);
        EXPECT_TRUE(name_parts[3] == "Services"
            || faker::testing::contains(company::data::company_suffixes, name_parts[3]));
    }
}

TEST(CompanyTest, should_generate_company_type)
{
    auto company_type = company::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::company_types, company_type);
}

TEST(CompanyTest, should_generate_company_industry)
{
    auto industry = company::industry();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::company_industries, industry);
}

TEST(CompanyTest, should_generate_buzz_phrase)
{
    auto buzz_phrase = company::buzz_phrase();

    FAKER_EXPECT_STRING_CONTAINS(buzz_phrase, company::data::buzz_verbs);
    FAKER_EXPECT_STRING_CONTAINS(buzz_phrase, company::data::buzz_adjectives);
    FAKER_EXPECT_STRING_CONTAINS(buzz_phrase, company::data::buzz_nouns);
}

TEST(CompanyTest, should_generate_buzz_verb)
{
    auto buzz_verb = company::buzz_verb();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzz_verbs, buzz_verb);
}

TEST(CompanyTest, should_generate_buzz_adjective)
{
    auto buzz_adjective = company::buzz_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzz_adjectives, buzz_adjective);
}

TEST(CompanyTest, should_generate_buzz_noun)
{
    auto buzz_noun = company::buzz_noun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::buzz_nouns, buzz_noun);
}

TEST(CompanyTest, should_generate_catch_phrase)
{
    auto catch_phrase = company::catch_phrase();

    FAKER_EXPECT_STRING_CONTAINS(catch_phrase, company::data::catch_phrase_adjectives);
    FAKER_EXPECT_STRING_CONTAINS(catch_phrase, company::data::catch_phrase_descriptors);
    FAKER_EXPECT_STRING_CONTAINS(catch_phrase, company::data::catch_phrase_nouns);
}

TEST(CompanyTest, should_generate_catch_phrase_adjective)
{
    auto catchy_adjective = company::catch_phrase_adjective();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::catch_phrase_adjectives, catchy_adjective);
}

TEST(CompanyTest, should_generate_catch_phrase_descriptor)
{
    auto catchy_descriptor = company::catch_phrase_descriptor();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::catch_phrase_descriptors, catchy_descriptor);
}

TEST(CompanyTest, should_generate_catch_phrase_noun)
{
    auto catchy_noun = company::catch_phrase_noun();

    FAKER_EXPECT_CONTAINER_CONTAINS(company::data::catch_phrase_nouns, catchy_noun);
}
