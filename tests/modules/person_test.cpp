#include "../bio_helper.h"
#include "../test_helpers.h"
#include <algorithm>
#include <array>
#include <common/strings.h>
#include <faker/person.h>
#include <modules/person_data.h>

using namespace ::testing;
using namespace faker;

namespace {
const std::vector<std::string> sexes { "Male", "Female" };

const std::unordered_map<Country, std::string> generatedTestName {
    { Country::England, "shouldGenerateEnglishName" },
    { Country::France, "shouldGenerateFrenchName" },
    { Country::Germany, "shouldGenerateGermanName" },
    { Country::Italy, "shouldGenerateItalianName" },
    { Country::Poland, "shouldGeneratePolishName" },
    { Country::Russia, "shouldGenerateRussianName" },
    { Country::Romania, "shouldGenerateRomanianName" },
    { Country::India, "shouldGenerateIndianName" },
    { Country::Finland, "shouldGenerateFinnishName" },
    { Country::Nepal, "shouldGenerateNepaleseName" },
    { Country::Spain, "shouldGenerateSpanishName" },
    { Country::Turkey, "shouldGenerateTurkishName" },
    { Country::Czech, "shouldGenerateCzechName" },
    { Country::Slovakia, "shouldGenerateSlovakName" },
    { Country::Ukraine, "shouldGenerateUkrainianName" },
    { Country::Denmark, "shouldGenerateDanishName" },
    { Country::Sweden, "shouldGenerateSwedishName" },
    { Country::Usa, "shouldGenerateAmericanName" },
    { Country::Brazil, "shouldGenerateBrazilianName" },
    { Country::Norway, "shouldGenerateNorwegianName" },
    { Country::Japan, "shouldGenerateJapaneseName" },
    { Country::Portugal, "shouldGeneratePortugueseName" },
    { Country::Hungary, "shouldGenerateHungarianName" },
    { Country::Croatia, "shouldGenerateCroatianName" },
    { Country::Greece, "shouldGenerateGreekName" },
    { Country::Slovenia, "shouldGenerateSlovenianName" },
    { Country::Austria, "shouldGenerateAustrianName" },
    { Country::Switzerland, "shouldGenerateSwissName" },
    { Country::Belgium, "shouldGenerateBelgianName" },
    { Country::Netherlands, "shouldGenerateDutchName" },
    { Country::China, "shouldGenerateChineseName" },
    { Country::Korea, "shouldGenerateKoreanName" },
    { Country::Canada, "shouldGenerateCanadianName" },
    { Country::Mexico, "shouldGenerateMexicanName" },
    { Country::Argentina, "shouldGenerateArgentinianName" },
    { Country::Australia, "shouldGenerateAustralianName" },
    { Country::Serbia, "shouldGenerateSerbianName" },
    { Country::Macedonia, "shouldGenerateMacedonianName" },
    { Country::Latvia, "shouldGenerateLatvianName" },
    { Country::Ireland, "shouldGenerateIrishName" },
    { Country::Belarus, "shouldGenerateBelarusianName" },
    { Country::Estonia, "shouldGenerateEstonianName" },
    { Country::Albania, "shouldGenerateAlbanianName" },
    { Country::Iran, "shouldGeneratePersianName" },
    { Country::Bulgaria, "shouldGenerateBulgarianName" },
    { Country::Moldova, "shouldGenerateMoldovanName" },
    { Country::Lithuania, "shouldGenerateLithuanianName" },
    { Country::Iceland, "shouldGenerateIcelandicName" },
    { Country::Palestine, "shouldGeneratePalestinianName" },
    { Country::Israel, "shouldGenerateIsraeliName" },
    { Country::Vietnam, "shouldGenerateVietnameseName" },
    { Country::Monaco, "shouldGenerateMonacanName" },
    { Country::Bosnia, "shouldGenerateBosnianNames" },
    { Country::Lebanon, "shouldGenerateLebaneseName" },
    { Country::Syria, "shouldGenerateSyrianName" },
    { Country::Malta, "shouldGenerateMalteseName" },
    { Country::SouthAfrica, "shouldGenerateSouthAfricanName" },
    { Country::Azerbaijan, "shouldGenerateAzerbaijaniName" },
    { Country::Ghana, "shouldGenerateGhanaianName" },
    { Country::Kazakhstan, "shouldGenerateKazakhName" },
    { Country::Maldives, "shouldGenerateMaldivianName" },
};
}

class PersonTest : public TestWithParam<Country> {
public:
    PersonTest()
    {
        initializePrefixes();

        initializeSuffixes();

        initializeMiddleNames();
    }

    void initializePrefixes()
    {
        for (const auto& [_, peopleNames] : person::data::countryToPeopleNamesMapping) {
            malesPrefixes.insert(malesPrefixes.end(), peopleNames.malesNames.prefixes.begin(),
                peopleNames.malesNames.prefixes.end());

            femalesPrefixes.insert(femalesPrefixes.end(), peopleNames.femalesNames.prefixes.begin(),
                peopleNames.femalesNames.prefixes.end());

            allPrefixes.insert(allPrefixes.end(), peopleNames.malesNames.prefixes.begin(),
                peopleNames.malesNames.prefixes.end());
            allPrefixes.insert(allPrefixes.end(), peopleNames.femalesNames.prefixes.begin(),
                peopleNames.femalesNames.prefixes.end());
        }
    }

    void initializeSuffixes()
    {
        for (const auto& [_, peopleNames] : person::data::countryToPeopleNamesMapping) {
            malesSuffixes.insert(malesSuffixes.end(), peopleNames.malesNames.suffixes.begin(),
                peopleNames.malesNames.suffixes.end());

            femalesSuffixes.insert(femalesSuffixes.end(), peopleNames.femalesNames.suffixes.begin(),
                peopleNames.femalesNames.suffixes.end());

            allSuffixes.insert(allSuffixes.end(), peopleNames.malesNames.suffixes.begin(),
                peopleNames.malesNames.suffixes.end());
            allSuffixes.insert(allSuffixes.end(), peopleNames.femalesNames.suffixes.begin(),
                peopleNames.femalesNames.suffixes.end());
        }
    }

    void initializeMiddleNames()
    {
        for (const auto& [_, peopleNames] : person::data::countryToPeopleNamesMapping) {
            malesMiddleNames.insert(malesMiddleNames.end(),
                peopleNames.malesNames.middleNames.begin(),
                peopleNames.malesNames.middleNames.end());

            femalesMiddleNames.insert(femalesMiddleNames.end(),
                peopleNames.femalesNames.middleNames.begin(),
                peopleNames.femalesNames.middleNames.end());

            allMiddleNames.insert(allMiddleNames.end(), peopleNames.malesNames.middleNames.begin(),
                peopleNames.malesNames.middleNames.end());
            allMiddleNames.insert(allMiddleNames.end(),
                peopleNames.femalesNames.middleNames.begin(),
                peopleNames.femalesNames.middleNames.end());
        }
    }

    std::vector<std::string> allPrefixes;
    std::vector<std::string> malesPrefixes;
    std::vector<std::string> femalesPrefixes;
    std::vector<std::string> allSuffixes;
    std::vector<std::string> malesSuffixes;
    std::vector<std::string> femalesSuffixes;
    std::vector<std::string> allMiddleNames;
    std::vector<std::string> malesMiddleNames;
    std::vector<std::string> femalesMiddleNames;
};

TEST_P(PersonTest, shouldGenerateFirstName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);
    auto firstNames = faker::testing::make_vector(
        peopleNames.malesNames.firstNames, peopleNames.femalesNames.firstNames);

    const auto generatedFirstName = person::first_name(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(firstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateMaleFirstName)
{
    const auto country = GetParam();
    const auto& malesFirstNames
        = person::data::countryToPeopleNamesMapping.at(country).malesNames.firstNames;

    const auto generatedFirstName = person::first_name(country, person::sex_t::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesFirstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateFemaleFirstName)
{
    const auto country = GetParam();
    const auto& femalesFirstNames
        = person::data::countryToPeopleNamesMapping.at(country).femalesNames.firstNames;

    const auto generatedFirstName = person::first_name(country, person::sex_t::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesFirstNames, generatedFirstName);
}

TEST_P(PersonTest, shouldGenerateLastNameMale)
{
    const auto country = GetParam();
    const auto& malesLastNames
        = person::data::countryToPeopleNamesMapping.at(country).malesNames.lastNames;

    const auto generatedLastName = person::last_name(country, person::sex_t::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesLastNames, generatedLastName);
}

TEST_P(PersonTest, shouldGenerateLastNameFemale)
{
    const auto country = GetParam();
    const auto& femalesLastNames
        = person::data::countryToPeopleNamesMapping.at(country).femalesNames.lastNames;

    const auto generatedLastName = person::last_name(country, person::sex_t::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesLastNames, generatedLastName);
}

TEST_P(PersonTest, shouldGenerateFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);
    auto firstNames = faker::testing::make_vector(
        peopleNames.malesNames.firstNames, peopleNames.femalesNames.firstNames);
    auto lastNames = faker::testing::make_vector(
        peopleNames.malesNames.lastNames, peopleNames.femalesNames.lastNames);

    const auto generatedFullName = person::full_name(country);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, firstNames);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, lastNames);
}

TEST_P(PersonTest, shouldGenerateMaleFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);

    const auto generatedFullName = person::full_name(country, person::sex_t::male);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.malesNames.firstNames);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.malesNames.lastNames);
}

TEST_P(PersonTest, shouldGenerateFemaleFullName)
{
    const auto country = GetParam();
    const auto& peopleNames = person::data::countryToPeopleNamesMapping.at(country);

    const auto generatedFullName = person::full_name(country, person::sex_t::female);

    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.femalesNames.firstNames);
    FAKER_EXPECT_STRING_CONTAINS(generatedFullName, peopleNames.femalesNames.lastNames);
}

const std::array<Country, 61> countries {
    Country::Usa,
    Country::England,
    Country::Poland,
    Country::Italy,
    Country::France,
    Country::Germany,
    Country::Russia,
    Country::Romania,
    Country::India,
    Country::Finland,
    Country::Nepal,
    Country::Spain,
    Country::Turkey,
    Country::Czech,
    Country::Slovakia,
    Country::Ukraine,
    Country::Denmark,
    Country::Sweden,
    Country::Brazil,
    Country::Norway,
    Country::Japan,
    Country::Portugal,
    Country::Hungary,
    Country::Croatia,
    Country::Greece,
    Country::Slovenia,
    Country::Austria,
    Country::Switzerland,
    Country::Belgium,
    Country::Netherlands,
    Country::China,
    Country::Korea,
    Country::Canada,
    Country::Mexico,
    Country::Argentina,
    Country::Australia,
    Country::Serbia,
    Country::Macedonia,
    Country::Albania,
    Country::Latvia,
    Country::Ireland,
    Country::Belarus,
    Country::Estonia,
    Country::Iran,
    Country::Bulgaria,
    Country::Moldova,
    Country::Lithuania,
    Country::Iceland,
    Country::Palestine,
    Country::Israel,
    Country::Vietnam,
    Country::Monaco,
    Country::Bosnia,
    Country::Lebanon,
    Country::Syria,
    Country::Malta,
    Country::SouthAfrica,
    Country::Azerbaijan,
    Country::Ghana,
    Country::Kazakhstan,
    Country::Maldives,
};

INSTANTIATE_TEST_SUITE_P(TestPersonNamesByCountries, PersonTest, ValuesIn(countries),
    [](const TestParamInfo<Country>& info) { return generatedTestName.at(info.param); });

TEST_F(PersonTest, shouldGenerateMiddleName)
{
    const auto generatedMiddleName = person::middle_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(allMiddleNames, generatedMiddleName);
}

TEST_F(PersonTest, shouldGeneratePrefix)
{
    const auto generatedPrefix = person::prefix();

    FAKER_EXPECT_CONTAINER_CONTAINS(allPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateMalePrefix)
{
    const auto generatedPrefix = person::prefix(person::sex_t::male);

    FAKER_EXPECT_CONTAINER_CONTAINS(malesPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateFemalePrefix)
{
    const auto generatedPrefix = person::prefix(person::sex_t::female);

    FAKER_EXPECT_CONTAINER_CONTAINS(femalesPrefixes, generatedPrefix);
}

TEST_F(PersonTest, shouldGenerateSuffix)
{
    const auto generatedSuffix = person::suffix();

    FAKER_EXPECT_CONTAINER_CONTAINS(allSuffixes, generatedSuffix);
}

TEST_F(PersonTest, shouldGenerateSex)
{
    const auto generatedSex = person::sex();

    FAKER_EXPECT_CONTAINER_CONTAINS(sexes, generatedSex);
}

TEST_F(PersonTest, shouldGenerateGender)
{
    const auto generatedGender = person::gender();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::genders, generatedGender);
}

TEST_F(PersonTest, shouldGenerateJobDescriptor)
{
    const auto generatedJobDescriptor = person::job_descriptor();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobDescriptors, generatedJobDescriptor);
}

TEST_F(PersonTest, shouldGenerateJobArea)
{
    const auto generatedJobArea = person::job_area();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobAreas, generatedJobArea);
}

TEST_F(PersonTest, shouldGenerateJobType)
{
    const auto generatedJobType = person::job_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobTypes, generatedJobType);
}

TEST_F(PersonTest, shouldGenerateJobTitle)
{
    const auto generatedJobTitle = person::job_title();

    const auto jobTitleElements = utils::split(generatedJobTitle, " ");

    const auto& generatedJobDescriptor = jobTitleElements[0];
    const auto& generatedJobArea = jobTitleElements[1];
    const auto& generatedJobType = jobTitleElements[2];

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobDescriptors, generatedJobDescriptor);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobAreas, generatedJobArea);
    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::jobTypes, generatedJobType);
}

TEST_F(PersonTest, shouldGenerateHobby)
{
    const auto generatedHobby = person::hobby();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::hobbies, generatedHobby);
}

TEST_F(PersonTest, shouldGenerateBio)
{
    const auto generatedBio = person::bio();

    ASSERT_TRUE(BioHelper::checkTokenFormat(generatedBio));
}

TEST_F(PersonTest, shouldGenerateLanguage)
{
    auto generatedLanguage = person::language();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::languages, generatedLanguage);
}

TEST_F(PersonTest, shouldGenerateNationality)
{
    auto generatedNationality = person::nationality();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::nationalities, generatedNationality);
}

TEST_F(PersonTest, shouldGenerateWesternZodiacs)
{
    auto generatedWesternZodiacs = person::western_zodiac();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::westernZodiacs, generatedWesternZodiacs);
}

TEST_F(PersonTest, shouldGenerateChineseZodiacs)
{
    const auto generatedChineseZodiacs = person::chinese_zodiac();

    FAKER_EXPECT_CONTAINER_CONTAINS(person::data::chineseZodiacs, generatedChineseZodiacs);
}

class PersonSexSuite : public TestWithParam<std::pair<person::language_t, person::sex_t>> { };

TEST_P(PersonSexSuite, shouldTranslateSexCorrectly)
{
    const auto language = GetParam().first;
    const auto sex = GetParam().second;

    const auto expectedTranslation = person::data::sexTranslations.at(language).at(sex);
    const auto actualTranslation = to_string(sex, language);

    ASSERT_EQ(expectedTranslation, actualTranslation);
}

std::vector<std::pair<person::language_t, person::sex_t>> languageSexPairs
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

std::string_view toString(person::language_t language)
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

INSTANTIATE_TEST_SUITE_P(TestPersonSexTranslation, PersonSexSuite, ValuesIn(languageSexPairs),
    [](const TestParamInfo<PersonSexSuite::ParamType>& info) {
        std::string result;
        result += toString(info.param.first);
        result += '_';
        result += to_string(info.param.second);
        return result;
    });

class PersonSsnSuite : public TestWithParam<person::ssn_country_t> { };

// TODO: add more precise tests
TEST_P(PersonSsnSuite, shouldGenerateSsn)
{
    const auto country = GetParam();

    const auto ssn = person::ssn(country);

    const auto expectedSsnLength = person::data::ssnLengths.at(country);

    ASSERT_EQ(ssn.size(), expectedSsnLength);
}

std::string_view toString(person::ssn_country_t country)
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

INSTANTIATE_TEST_SUITE_P(TestPersonSsn, PersonSsnSuite,
    ValuesIn(person::data::supportedSsnCountries),
    [](const TestParamInfo<PersonSsnSuite::ParamType>& info) {
        std::string result("shouldGenerate");
        result += toString(info.param);
        result += "Ssn";
        return result;
    });
