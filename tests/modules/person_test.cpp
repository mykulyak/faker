#include "../bio_helper.h"
#include "../test_helpers.h"
#include <array>
#include <common/strings.h>
#include <faker/person.h>
#include <modules/person_data.h>

using namespace ::testing;
using namespace faker;

namespace {
const std::vector<std::string> sexes { "Male", "Female" };

const std::unordered_map<country_t, std::string> generated_country_test_names {
    { country_t::england, "shouldGenerateEnglishName" },
    { country_t::france, "shouldGenerateFrenchName" },
    { country_t::germany, "shouldGenerateGermanName" },
    { country_t::italy, "shouldGenerateItalianName" },
    { country_t::poland, "shouldGeneratePolishName" },
    { country_t::russia, "shouldGenerateRussianName" },
    { country_t::romania, "shouldGenerateRomanianName" },
    { country_t::india, "shouldGenerateIndianName" },
    { country_t::finland, "shouldGenerateFinnishName" },
    { country_t::nepal, "shouldGenerateNepaleseName" },
    { country_t::spain, "shouldGenerateSpanishName" },
    { country_t::turkey, "shouldGenerateTurkishName" },
    { country_t::czech, "shouldGenerateCzechName" },
    { country_t::slovakia, "shouldGenerateSlovakName" },
    { country_t::ukraine, "shouldGenerateUkrainianName" },
    { country_t::denmark, "shouldGenerateDanishName" },
    { country_t::sweden, "shouldGenerateSwedishName" },
    { country_t::usa, "shouldGenerateAmericanName" },
    { country_t::brazil, "shouldGenerateBrazilianName" },
    { country_t::norway, "shouldGenerateNorwegianName" },
    { country_t::japan, "shouldGenerateJapaneseName" },
    { country_t::portugal, "shouldGeneratePortugueseName" },
    { country_t::hungary, "shouldGenerateHungarianName" },
    { country_t::croatia, "shouldGenerateCroatianName" },
    { country_t::greece, "shouldGenerateGreekName" },
    { country_t::slovenia, "shouldGenerateSlovenianName" },
    { country_t::austria, "shouldGenerateAustrianName" },
    { country_t::switzerland, "shouldGenerateSwissName" },
    { country_t::belgium, "shouldGenerateBelgianName" },
    { country_t::netherlands, "shouldGenerateDutchName" },
    { country_t::china, "shouldGenerateChineseName" },
    { country_t::korea, "shouldGenerateKoreanName" },
    { country_t::canada, "shouldGenerateCanadianName" },
    { country_t::mexico, "shouldGenerateMexicanName" },
    { country_t::argentina, "shouldGenerateArgentinianName" },
    { country_t::australia, "shouldGenerateAustralianName" },
    { country_t::serbia, "shouldGenerateSerbianName" },
    { country_t::macedonia, "shouldGenerateMacedonianName" },
    { country_t::latvia, "shouldGenerateLatvianName" },
    { country_t::ireland, "shouldGenerateIrishName" },
    { country_t::belarus, "shouldGenerateBelarusianName" },
    { country_t::estonia, "shouldGenerateEstonianName" },
    { country_t::albania, "shouldGenerateAlbanianName" },
    { country_t::iran, "shouldGeneratePersianName" },
    { country_t::bulgaria, "shouldGenerateBulgarianName" },
    { country_t::moldova, "shouldGenerateMoldovanName" },
    { country_t::lithuania, "shouldGenerateLithuanianName" },
    { country_t::iceland, "shouldGenerateIcelandicName" },
    { country_t::palestine, "shouldGeneratePalestinianName" },
    { country_t::israel, "shouldGenerateIsraeliName" },
    { country_t::vietnam, "shouldGenerateVietnameseName" },
    { country_t::monaco, "shouldGenerateMonacanName" },
    { country_t::bosnia, "shouldGenerateBosnianNames" },
    { country_t::lebanon, "shouldGenerateLebaneseName" },
    { country_t::syria, "shouldGenerateSyrianName" },
    { country_t::malta, "shouldGenerateMalteseName" },
    { country_t::south_africa, "shouldGenerateSouthAfricanName" },
    { country_t::azerbaijan, "shouldGenerateAzerbaijaniName" },
    { country_t::ghana, "shouldGenerateGhanaianName" },
    { country_t::kazakhstan, "shouldGenerateKazakhName" },
    { country_t::maldives, "shouldGenerateMaldivianName" },
};

const std::array<country_t, 61> countries {
    country_t::usa,
    country_t::england,
    country_t::poland,
    country_t::italy,
    country_t::france,
    country_t::germany,
    country_t::russia,
    country_t::romania,
    country_t::india,
    country_t::finland,
    country_t::nepal,
    country_t::spain,
    country_t::turkey,
    country_t::czech,
    country_t::slovakia,
    country_t::ukraine,
    country_t::denmark,
    country_t::sweden,
    country_t::brazil,
    country_t::norway,
    country_t::japan,
    country_t::portugal,
    country_t::hungary,
    country_t::croatia,
    country_t::greece,
    country_t::slovenia,
    country_t::austria,
    country_t::switzerland,
    country_t::belgium,
    country_t::netherlands,
    country_t::china,
    country_t::korea,
    country_t::canada,
    country_t::mexico,
    country_t::argentina,
    country_t::australia,
    country_t::serbia,
    country_t::macedonia,
    country_t::albania,
    country_t::latvia,
    country_t::ireland,
    country_t::belarus,
    country_t::estonia,
    country_t::iran,
    country_t::bulgaria,
    country_t::moldova,
    country_t::lithuania,
    country_t::iceland,
    country_t::palestine,
    country_t::israel,
    country_t::vietnam,
    country_t::monaco,
    country_t::bosnia,
    country_t::lebanon,
    country_t::syria,
    country_t::malta,
    country_t::south_africa,
    country_t::azerbaijan,
    country_t::ghana,
    country_t::kazakhstan,
    country_t::maldives,
};

std::vector<std::pair<person::language_t, person::sex_t>> language_sex_pairs
    = { { person::language_t::english, person::sex_t::male },
          { person::language_t::english, person::sex_t::female },
          { person::language_t::polish, person::sex_t::male },
          { person::language_t::polish, person::sex_t::female },
          { person::language_t::italian, person::sex_t::male },
          { person::language_t::italian, person::sex_t::female },
          { person::language_t::french, person::sex_t::male },
          { person::language_t::french, person::sex_t::female },
          { person::language_t::german, person::sex_t::male },
          { person::language_t::german, person::sex_t::female },
          { person::language_t::russian, person::sex_t::male },
          { person::language_t::russian, person::sex_t::female },
          { person::language_t::romanian, person::sex_t::male },
          { person::language_t::romanian, person::sex_t::female },
          { person::language_t::hindi, person::sex_t::male },
          { person::language_t::hindi, person::sex_t::female },
          { person::language_t::finnish, person::sex_t::male },
          { person::language_t::finnish, person::sex_t::female },
          { person::language_t::nepali, person::sex_t::male },
          { person::language_t::nepali, person::sex_t::female },
          { person::language_t::spanish, person::sex_t::male },
          { person::language_t::spanish, person::sex_t::female },
          { person::language_t::turkish, person::sex_t::male },
          { person::language_t::turkish, person::sex_t::female },
          { person::language_t::czech, person::sex_t::male },
          { person::language_t::czech, person::sex_t::female },
          { person::language_t::slovak, person::sex_t::male },
          { person::language_t::slovak, person::sex_t::female },
          { person::language_t::ukrainian, person::sex_t::male },
          { person::language_t::ukrainian, person::sex_t::female },
          { person::language_t::danish, person::sex_t::male },
          { person::language_t::danish, person::sex_t::female },
          { person::language_t::swedish, person::sex_t::male },
          { person::language_t::swedish, person::sex_t::female },
          { person::language_t::portuguese, person::sex_t::male },
          { person::language_t::portuguese, person::sex_t::female },
          { person::language_t::norwegian, person::sex_t::male },
          { person::language_t::norwegian, person::sex_t::female },
          { person::language_t::japanese, person::sex_t::male },
          { person::language_t::japanese, person::sex_t::female },
          { person::language_t::hungarian, person::sex_t::male },
          { person::language_t::hungarian, person::sex_t::female },
          { person::language_t::croatian, person::sex_t::male },
          { person::language_t::croatian, person::sex_t::female },
          { person::language_t::greek, person::sex_t::male },
          { person::language_t::greek, person::sex_t::female },
          { person::language_t::slovene, person::sex_t::male },
          { person::language_t::slovene, person::sex_t::female },
          { person::language_t::dutch, person::sex_t::male },
          { person::language_t::dutch, person::sex_t::female },
          { person::language_t::mandarin, person::sex_t::male },
          { person::language_t::mandarin, person::sex_t::female },
          { person::language_t::korean, person::sex_t::male },
          { person::language_t::korean, person::sex_t::female },
          { person::language_t::serbian, person::sex_t::male },
          { person::language_t::serbian, person::sex_t::female },
          { person::language_t::macedonian, person::sex_t::male },
          { person::language_t::macedonian, person::sex_t::female },
          { person::language_t::albanian, person::sex_t::male },
          { person::language_t::albanian, person::sex_t::female },
          { person::language_t::latvian, person::sex_t::male },
          { person::language_t::latvian, person::sex_t::female },
          { person::language_t::irish, person::sex_t::male },
          { person::language_t::irish, person::sex_t::female },
          { person::language_t::belarusian, person::sex_t::male },
          { person::language_t::belarusian, person::sex_t::female },
          { person::language_t::estonian, person::sex_t::male },
          { person::language_t::estonian, person::sex_t::female } };

std::string_view to_string(person::language_t language)
{
    switch (language) {
    case person::language_t::english:
        return "English";
    case person::language_t::polish:
        return "Polish";
    case person::language_t::italian:
        return "Italian";
    case person::language_t::french:
        return "French";
    case person::language_t::german:
        return "German";
    case person::language_t::russian:
        return "Russian";
    case person::language_t::romanian:
        return "Romanian";
    case person::language_t::hindi:
        return "Hindi";
    case person::language_t::finnish:
        return "Finnish";
    case person::language_t::nepali:
        return "Nepali";
    case person::language_t::spanish:
        return "Spanish";
    case person::language_t::turkish:
        return "Turkish";
    case person::language_t::czech:
        return "Czech";
    case person::language_t::slovak:
        return "Slovak";
    case person::language_t::ukrainian:
        return "Ukrainian";
    case person::language_t::danish:
        return "Danish";
    case person::language_t::swedish:
        return "Swedish";
    case person::language_t::portuguese:
        return "Portuguese";
    case person::language_t::norwegian:
        return "Norwegian";
    case person::language_t::japanese:
        return "Japanese";
    case person::language_t::hungarian:
        return "Hungarian";
    case person::language_t::croatian:
        return "Croatian";
    case person::language_t::greek:
        return "Greek";
    case person::language_t::slovene:
        return "Slovene";
    case person::language_t::dutch:
        return "Dutch";
    case person::language_t::mandarin:
        return "Mandarin";
    case person::language_t::korean:
        return "Korean";
    case person::language_t::serbian:
        return "Serbian";
    case person::language_t::macedonian:
        return "Macedonian";
    case person::language_t::albanian:
        return "Albanian";
    case person::language_t::latvian:
        return "Latvian";
    case person::language_t::irish:
        return "Irish";
    case person::language_t::belarusian:
        return "Belarusian";
    case person::language_t::estonian:
        return "Estonian";
    default:
        throw std::invalid_argument("Invalid language");
    }
}

std::string_view to_string(person::ssn_country_t country)
{
    switch (country) {
    case person::ssn_country_t::usa:
        return "UnitedStates";
    case person::ssn_country_t::england:
        return "UnitedKingdom";
    case person::ssn_country_t::poland:
        return "Poland";
    case person::ssn_country_t::italy:
        return "Italy";
    case person::ssn_country_t::france:
        return "France";
    case person::ssn_country_t::germany:
        return "Germany";
    case person::ssn_country_t::india:
        return "India";
    case person::ssn_country_t::spain:
        return "Spain";
    default:
        throw std::invalid_argument("Invalid country");
    }
}

}

class PersonTest : public TestWithParam<country_t> {
public:
    PersonTest()
    {
        for (const auto& [_, names_data] : person::data::people_names) {
            male_prefixes.insert(male_prefixes.end(), names_data.males_names.prefixes.begin(),
                names_data.males_names.prefixes.end());

            female_prefixes.insert(female_prefixes.end(), names_data.female_names.prefixes.begin(),
                names_data.female_names.prefixes.end());

            all_prefixes.insert(all_prefixes.end(), names_data.males_names.prefixes.begin(),
                names_data.males_names.prefixes.end());
            all_prefixes.insert(all_prefixes.end(), names_data.female_names.prefixes.begin(),
                names_data.female_names.prefixes.end());

            male_suffixes.insert(male_suffixes.end(), names_data.males_names.suffixes.begin(),
                names_data.males_names.suffixes.end());

            female_suffixes.insert(female_suffixes.end(), names_data.female_names.suffixes.begin(),
                names_data.female_names.suffixes.end());

            all_suffixes.insert(all_suffixes.end(), names_data.males_names.suffixes.begin(),
                names_data.males_names.suffixes.end());
            all_suffixes.insert(all_suffixes.end(), names_data.female_names.suffixes.begin(),
                names_data.female_names.suffixes.end());

            male_middle_names.insert(male_middle_names.end(),
                names_data.males_names.middle_names.begin(),
                names_data.males_names.middle_names.end());

            female_middle_names.insert(female_middle_names.end(),
                names_data.female_names.middle_names.begin(),
                names_data.female_names.middle_names.end());

            all_middle_names.insert(all_middle_names.end(),
                names_data.males_names.middle_names.begin(),
                names_data.males_names.middle_names.end());
            all_middle_names.insert(all_middle_names.end(),
                names_data.female_names.middle_names.begin(),
                names_data.female_names.middle_names.end());
        }
    }

    std::vector<std::string> all_prefixes;
    std::vector<std::string> male_prefixes;
    std::vector<std::string> female_prefixes;
    std::vector<std::string> all_suffixes;
    std::vector<std::string> male_suffixes;
    std::vector<std::string> female_suffixes;
    std::vector<std::string> all_middle_names;
    std::vector<std::string> male_middle_names;
    std::vector<std::string> female_middle_names;
};

TEST_P(PersonTest, should_generate_first_name)
{
    const auto country = GetParam();

    const auto first_name = person::first_name(country);
    const auto male_first_name = person::first_name(country, person::sex_t::male);
    const auto female_first_name = person::first_name(country, person::sex_t::female);

    const auto& people_names = person::data::people_names.at(country);
    EXPECT_TRUE(faker::testing::contains(people_names.males_names.first_names, first_name)
        || faker::testing::contains(people_names.female_names.first_names, first_name));
    FAKER_EXPECT_CONTAINER_CONTAINS(people_names.males_names.first_names, male_first_name);
    FAKER_EXPECT_CONTAINER_CONTAINS(people_names.female_names.first_names, female_first_name);
}

TEST_P(PersonTest, should_generate_last_name)
{
    const auto country = GetParam();

    const auto last_male_name = person::last_name(country, person::sex_t::male);
    const auto last_female_name = person::last_name(country, person::sex_t::female);

    const auto& person_names = person::data::people_names.at(country);
    FAKER_EXPECT_CONTAINER_CONTAINS(person_names.males_names.last_names, last_male_name);
    FAKER_EXPECT_CONTAINER_CONTAINS(person_names.female_names.last_names, last_female_name);
}

TEST_P(PersonTest, should_generate_full_name)
{
    const auto country = GetParam();

    const auto full_name = person::full_name(country);
    const auto male_full_name = person::full_name(country, person::sex_t::male);
    const auto female_full_name = person::full_name(country, person::sex_t::female);

    const auto& people_names = person::data::people_names.at(country);
    EXPECT_TRUE(faker::testing::contains(full_name, people_names.males_names.first_names)
        || faker::testing::contains(full_name, people_names.female_names.first_names));
    EXPECT_TRUE(faker::testing::contains(full_name, people_names.males_names.last_names)
        || faker::testing::contains(full_name, people_names.female_names.last_names));

    FAKER_EXPECT_STRING_CONTAINS(male_full_name, people_names.males_names.first_names);
    FAKER_EXPECT_STRING_CONTAINS(male_full_name, people_names.males_names.last_names);

    FAKER_EXPECT_STRING_CONTAINS(female_full_name, people_names.female_names.first_names);
    FAKER_EXPECT_STRING_CONTAINS(female_full_name, people_names.female_names.last_names);
}

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
    [](const TestParamInfo<country_t>& info) {
        return generated_country_test_names.at(info.param);
    });

TEST_F(PersonTest, should_generate_middle_name)
{
    const auto middle_name = person::middle_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(all_middle_names, middle_name);
}

TEST_F(PersonTest, should_generate_prefix)
{
    const auto perfix = person::prefix();
    const auto male_prefix = person::prefix(person::sex_t::male);
    const auto female_prefix = person::prefix(person::sex_t::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(all_prefixes, perfix);
    FAKER_EXPECT_CONTAINER_CONTAINS(male_prefixes, male_prefix);
    FAKER_EXPECT_CONTAINER_CONTAINS(female_prefixes, female_prefix);
}

TEST_F(PersonTest, should_generate_suffix)
{
    const auto suffix = person::suffix();

    FAKER_EXPECT_CONTAINER_CONTAINS(all_suffixes, suffix);
}

TEST_F(PersonTest, should_generate_sex)
{
    const auto sex = person::sex();

    FAKER_EXPECT_CONTAINER_CONTAINS(sexes, sex);
}

TEST_F(PersonTest, should_generate_gender)
{
    const auto gender = person::gender();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::genders, gender);
}

TEST_F(PersonTest, should_generate_job_descriptor)
{
    const auto job_descriptor = person::job_descriptor();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_descriptors, job_descriptor);
}

TEST_F(PersonTest, should_generate_job_area)
{
    const auto job_area = person::job_area();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, job_area);
}

TEST_F(PersonTest, should_generate_job_type)
{
    const auto job_type = person::job_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_types, job_type);
}

TEST_F(PersonTest, should_generate_job_title)
{
    const auto job_title = person::job_title();

    const auto job_title_parts = utils::split(job_title, " ");
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_descriptors, job_title_parts[0]);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_areas, job_title_parts[1]);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::job_types, job_title_parts[2]);
}

TEST_F(PersonTest, should_generate_hobby)
{
    const auto hobby = person::hobby();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::hobbies, hobby);
}

TEST_F(PersonTest, should_generate_bio)
{
    const auto bio = person::bio();

    ASSERT_TRUE(faker::testing::check_bio_format(bio));
}

TEST_F(PersonTest, should_generate_language)
{
    auto language = person::language();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::languages, language);
}

TEST_F(PersonTest, should_generate_nationality)
{
    auto nationality = person::nationality();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::nationalities, nationality);
}

TEST_F(PersonTest, should_generate_western_zodiacs)
{
    auto western_zodiacs = person::western_zodiac();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::western_zodiacs, western_zodiacs);
}

TEST_F(PersonTest, should_generate_chinese_zodiacs)
{
    const auto chinese_zodiacs = person::chinese_zodiac();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::chinese_zodiacs, chinese_zodiacs);
}

class PersonSexSuite : public TestWithParam<std::pair<person::language_t, person::sex_t>> { };

TEST_P(PersonSexSuite, should_correctly_translate_sex)
{
    const auto language = GetParam().first;
    const auto sex = GetParam().second;

    auto translation = to_string(sex, language);

    ASSERT_EQ(translation, person::data::sex_translations.at(language).at(sex));
}

INSTANTIATE_TEST_SUITE_P(TestPersonSexTranslation, PersonSexSuite, ValuesIn(language_sex_pairs),
    [](const TestParamInfo<PersonSexSuite::ParamType>& info) {
        std::string result;
        result += to_string(info.param.first);
        result += '_';
        result += to_string(info.param.second);
        return result;
    });

class PersonSsnSuite : public TestWithParam<person::ssn_country_t> { };

// TODO: add more precise tests
TEST_P(PersonSsnSuite, should_generate_ssn)
{
    const auto country = GetParam();

    const auto ssn = person::ssn(country);

    ASSERT_EQ(ssn.size(), person::data::ssn_lengths.at(country));
}

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite,
    ValuesIn(person::data::supported_ssn_countries),
    [](const TestParamInfo<PersonSsnSuite::ParamType>& info) {
        std::string result("shouldGenerate");
        result += to_string(info.param);
        result += "Ssn";
        return result;
    });
