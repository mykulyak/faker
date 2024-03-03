#include "../test_helpers.h"
#include <algorithm>
#include <common/strings.h>
#include <faker/location.h>
#include <modules/location_data.h>
#include <modules/person_data.h>
#include <modules/string_data.h>

using namespace ::testing;
using namespace faker;

namespace {
const std::array<location::address_country, 14> address_countries {
    location::address_country::usa,
    location::address_country::poland,
    location::address_country::france,
    location::address_country::russia,
    location::address_country::ukraine,
    location::address_country::italy,
    location::address_country::germany,
    location::address_country::czechia,
    location::address_country::india,
    location::address_country::denmark,
    location::address_country::australia,
    location::address_country::spain,
    location::address_country::brazil,
    location::address_country::finland,
};

const location::data::country_addresses_info& get_country_addresses(
    location::address_country country)
{
    switch (country) {
    case location::address_country::usa:
        return location::data::usa_addresses;
    case location::address_country::poland:
        return location::data::poland_addresses;
    case location::address_country::russia:
        return location::data::russia_addresses;
    case location::address_country::france:
        return location::data::france_addresses;
    case location::address_country::ukraine:
        return location::data::ukraine_addresses;
    case location::address_country::italy:
        return location::data::italy_addresses;
    case location::address_country::germany:
        return location::data::germany_addresses;
    case location::address_country::czechia:
        return location::data::czech_addresses;
    case location::address_country::australia:
        return location::data::australia_addresses;
    case location::address_country::india:
        return location::data::india_addresses;
    case location::address_country::denmark:
        return location::data::denmark_addresses;
    case location::address_country::spain:
        return location::data::spain_addresses;
    case location::address_country::brazil:
        return location::data::brazil_addresses;
    case location::address_country::finland:
        return location::data::finland_addresses;
    case location::address_country::estonia:
        return location::data::estonia_addresses;
    default:
        throw std::invalid_argument("Invalid country");
    }
}
}

const std::unordered_map<location::address_country, std::string> generated_test_names {
    { location::address_country::usa, "shouldGenerateAmericanAddress" },
    { location::address_country::france, "shouldGenerateFrenchAddress" },
    { location::address_country::poland, "shouldGeneratePolishAddress" },
    { location::address_country::russia, "shouldGenerateRussianAddress" },
    { location::address_country::ukraine, "shouldGenerateUkrainianAddress" },
    { location::address_country::italy, "shouldGenerateItalianAddress" },
    { location::address_country::germany, "shouldGenerateGermanAddress" },
    { location::address_country::czechia, "shouldGenerateCzechAddress" },
    { location::address_country::australia, "shouldGenerateAustraliaAddress" },
    { location::address_country::india, "shouldGenerateIndiaAddress" },
    { location::address_country::denmark, "shouldGenerateDenmarkAddress" },
    { location::address_country::spain, "shouldGenerateSpainAddress" },
    { location::address_country::brazil, "shouldGenerateBrazilAddress" },
    { location::address_country::finland, "shouldGenerateFinlandAddress" },
    { location::address_country::estonia, "shouldGenerateEstoniaAddress" },
};

class LocationTest : public TestWithParam<location::address_country> {
public:
    static bool contains_only_digits(std::string_view data)
    {
        return faker::testing::all_of(
            data, [](char ch) { return string::data::digits.find(ch) != std::string::npos; });
    }
};

TEST_P(LocationTest, should_generate_county)
{
    const auto country = GetParam();

    const auto county = location::county(country);

    const auto& address_data = get_country_addresses(country);
    EXPECT_TRUE(faker::testing::contains(address_data.counties, county)
        || (address_data.counties.empty() && county.empty()));
}

TEST_P(LocationTest, should_generate_state)
{
    const auto country = GetParam();

    const auto state = location::state(country);

    const auto& address_data = get_country_addresses(country);
    FAKER_EXPECT_CONTAINER_CONTAINS(address_data.states, state);
}

TEST_P(LocationTest, should_generate_city)
{
    const auto country = GetParam();

    const auto city_name = location::city(country);

    const auto& address_data = get_country_addresses(country);
    if (country == faker::location::address_country::brazil) {
        const auto city_name_parts = utils::split(city_name, " ");

        const auto& city_prefix = city_name_parts[0];

        EXPECT_TRUE(
            faker::testing::contains_any_of(city_prefix, person::data::brazilian_male_first_names)
            || faker::testing::contains_any_of(
                city_prefix, person::data::brazilian_female_first_names)
            || faker::testing::contains_any_of(city_prefix, person::data::brazilian_last_names)
            || faker::testing::contains_any_of(city_name, location::data::brazil_city_suffixes));
    } else {
        FAKER_EXPECT_CONTAINER_CONTAINS(address_data.cities, city_name);
    }
}

TEST_P(LocationTest, should_generate_zip_code)
{
    const auto country = GetParam();

    const auto zip_code = location::zip_code(country);

    EXPECT_EQ(zip_code.size(), get_country_addresses(country).zip_code_format.size());
    FAKER_EXPECT_REGEX_MATCHES(zip_code, R"(^\d+(-\d+)*$)");
}

TEST_P(LocationTest, should_generate_building_number)
{
    const auto country = GetParam();

    const auto building_number = location::building_number(country);

    const auto building_number_formats = get_country_addresses(country).building_number_formats;
    EXPECT_TRUE(faker::testing::any_of(
        building_number_formats, [&building_number](auto building_number_format) {
            for (std::size_t i = 0; i < building_number_format.size(); i++) {
                if (building_number_format[i] == '#') {
                    if (string::data::digits.find(building_number[i]) == std::string::npos) {
                        return false;
                    }
                } else if (building_number[i] != building_number_format[i]) {
                    return false;
                }
            }
            return true;
        }));
}

TEST_P(LocationTest, should_generate_secondary_address)
{
    const auto country = GetParam();

    const auto secondary_address = location::secondary_address(country);

    const auto& address_data = get_country_addresses(country);
    EXPECT_TRUE((address_data.secondary_address_formats.empty() && secondary_address.empty())
        || faker::testing::any_of(
            address_data.secondary_address_formats, [&secondary_address](auto address_format) {
                for (std::size_t i = 0; i < address_format.size(); i++) {
                    if (address_format[i] == '#') {
                        if (string::data::digits.find(secondary_address[i]) == std::string::npos) {
                            return false;
                        }
                    } else if (address_format[i] != secondary_address[i]) {
                        return false;
                    }
                }
                return true;
            }));
}

INSTANTIATE_TEST_SUITE_P(TestLocationByCountries, LocationTest, ValuesIn(address_countries),
    [](const TestParamInfo<location::address_country>& info) {
        return generated_test_names.at(info.param);
    });

TEST_F(LocationTest, should_generate_street)
{
    const auto street_usa = location::street();
    const auto street_usa_parts = utils::split(street_usa, " ");
    EXPECT_EQ(street_usa_parts.size(), 2u);
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_usa_parts[0], person::data::english_male_first_names)
        || faker::testing::contains_any_of(
            street_usa_parts[0], person::data::english_female_first_names)
        || faker::testing::contains_any_of(street_usa_parts[0], person::data::english_last_names));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::usa_street_suffixes, street_usa_parts[1]);

    const auto street_pl = location::street(location::address_country::poland);
    const auto street_pl_parts = utils::split(street_pl, " ");
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::poland_street_prefixes, street_pl_parts[0]);
    FAKER_EXPECT_CONTAINER_CONTAINS(
        location::data::poland_street_names, street_pl.substr(street_pl_parts[0].size() + 1));

    const auto street_ua = location::street(location::address_country::ukraine);
    const auto street_ua_parts = utils::split(street_ua, " ");
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::ukraine_street_prefixes, street_ua_parts[0]);
    const auto& street_ua_suffix
        = utils::join({ street_ua_parts.begin() + 1, street_ua_parts.end() });
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_ua_suffix, person::data::ukrainian_male_first_names)
        || faker::testing::contains_any_of(
            street_ua_suffix, person::data::ukrainian_female_first_names)
        || faker::testing::contains_any_of(
            street_ua_suffix, person::data::ukrainian_males_last_names)
        || faker::testing::contains_any_of(
            street_ua_suffix, person::data::ukrainian_female_first_names)
        || faker::testing::contains_any_of(street_ua_suffix, location::data::ukraine_street_names));

    const auto street_es = location::street(location::address_country::estonia);
    EXPECT_TRUE(faker::testing::contains_any_of(street_es, location::data::estonia_street_names));

    const auto street_de = location::street(location::address_country::germany);
    EXPECT_TRUE(faker::testing::contains_any_of(street_de, location::data::germany_street_names));

    const auto street_cz = location::street(location::address_country::czechia);
    EXPECT_TRUE(faker::testing::contains_any_of(street_cz, location::data::czech_street_names));

    const auto street_dk = location::street(location::address_country::denmark);
    EXPECT_TRUE(faker::testing::contains_any_of(street_dk, location::data::denmark_street_names));

    const auto street_fr = location::street(location::address_country::france);
    const auto street_fr_parts = utils::split(street_fr, " ");
    EXPECT_GE(street_fr_parts.size(), 2u);
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::france_street_prefixes, street_fr_parts[0]);
    FAKER_EXPECT_CONTAINER_CONTAINS(
        location::data::france_street_suffixes, street_fr.substr(street_fr_parts[0].size() + 1));

    const auto street_it = location::street(location::address_country::italy);
    const auto street_it_parts = utils::split(street_it, " ");
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::italy_street_prefixes, street_it_parts[0]);
    const auto& street_it_suffix
        = utils::join({ street_it_parts.begin() + 1, street_it_parts.end() });
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_it_suffix, person::data::italian_male_first_names)
        || faker::testing::contains_any_of(
            street_it_suffix, person::data::italian_female_first_names)
        || faker::testing::contains_any_of(street_it_suffix, person::data::italian_last_names));

    const auto street_au = location::street(location::address_country::australia);
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_au, person::data::australian_male_first_names)
        || faker::testing::contains_any_of(street_au, person::data::australian_female_first_names)
        || faker::testing::contains_any_of(street_au, person::data::australian_last_names));
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_au, location::data::australia_street_suffixes));

    const auto street_in = location::street(location::address_country::india);
    const auto street_in_parts = utils::split(street_in, " ");
    EXPECT_GE(street_in_parts.size(), 2u);
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::india_street_suffixes,
        utils::join({ street_in_parts.begin() + 1, street_in_parts.end() }));

    const auto street_sp = location::street(location::address_country::spain);
    EXPECT_TRUE(faker::testing::contains_any_of(street_sp, person::data::spanish_male_first_names)
        || faker::testing::contains_any_of(street_sp, person::data::spanish_female_first_names)
        || faker::testing::contains_any_of(street_sp, person::data::spanish_last_names));
    EXPECT_TRUE(faker::testing::contains_any_of(street_sp, location::data::spain_street_suffixes));

    const auto street_fi = location::street(location::address_country::finland);
    const auto street_fi_parts = utils::split(street_fi, " ");
    EXPECT_GE(street_fi_parts.size(), 2u);
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_fi_parts[0], person::data::finnish_male_first_names)
        || faker::testing::contains_any_of(
            street_fi_parts[0], person::data::finnish_female_first_names)
        || faker::testing::contains_any_of(street_fi_parts[0], person::data::finnish_last_names));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::finland_street_suffixes, street_fi_parts[1]);

    const auto street_ru = location::street(location::address_country::russia);
    const auto street_ru_parts = utils::split(street_ru, " ");
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::russia_street_prefixes, street_ru_parts[0]);
    const auto street_ru_tail = street_ru.substr(street_ru_parts[0].size() + 1);
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_ru_tail, person::data::russian_male_first_names)
        || faker::testing::contains_any_of(street_ru_tail, person::data::russian_female_first_names)
        || faker::testing::contains_any_of(street_ru_tail, person::data::russian_male_last_names)
        || faker::testing::contains_any_of(street_ru_tail, person::data::russian_female_last_names)
        || faker::testing::contains_any_of(street_ru_tail, location::data::russia_street_names));
}

TEST_F(LocationTest, should_generate_street_address)
{
    const auto address_usa = location::street_address();
    const auto street_usa_parts = utils::split(address_usa, " ");
    EXPECT_EQ(street_usa_parts.size(), 3u);
    FAKER_EXPECT_REGEX_MATCHES(street_usa_parts[0], R"(^\d{3,5}$)");
    EXPECT_TRUE(
        faker::testing::contains_any_of(street_usa_parts[1], person::data::english_male_first_names)
        || faker::testing::contains_any_of(
            street_usa_parts[1], person::data::english_female_first_names)
        || faker::testing::contains_any_of(street_usa_parts[1], person::data::english_last_names));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::usa_street_suffixes, street_usa_parts[2]);

    const auto address_pl = location::street_address(location::address_country::poland);
    EXPECT_TRUE(
        faker::testing::contains_any_of(address_pl, location::data::poland_street_prefixes));
    EXPECT_TRUE(faker::testing::contains_any_of(address_pl, location::data::poland_street_names));

    const auto address_ua = location::street_address(location::address_country::ukraine);
    EXPECT_TRUE(
        faker::testing::contains_any_of(address_ua, location::data::ukraine_street_prefixes));
    EXPECT_TRUE(
        faker::testing::contains_any_of(address_ua, person::data::ukrainian_male_first_names)
        || faker::testing::contains_any_of(address_ua, person::data::ukrainian_males_last_names)
        || faker::testing::contains_any_of(address_ua, person::data::ukrainian_female_first_names)
        || faker::testing::contains_any_of(address_ua, person::data::ukrainian_female_last_names)
        || faker::testing::contains_any_of(address_ua, location::data::ukraine_street_names));

    const auto address_es = location::street_address(location::address_country::estonia);
    EXPECT_TRUE(faker::testing::contains_any_of(address_es, location::data::estonia_street_names));

    const auto address_de = location::street_address(location::address_country::germany);
    EXPECT_TRUE(faker::testing::contains_any_of(address_de, location::data::germany_street_names));

    const auto address_cz = location::street_address(location::address_country::czechia);
    EXPECT_TRUE(faker::testing::contains_any_of(address_cz, location::data::czech_street_names));

    const auto address_dk = location::street_address(location::address_country::denmark);
    EXPECT_TRUE(faker::testing::contains_any_of(address_dk, location::data::denmark_street_names));

    const auto address_fr = location::street_address(location::address_country::france);
    const auto street_fr_parts = utils::split(address_fr, " ");
    EXPECT_GE(street_fr_parts.size(), 3u);
    FAKER_EXPECT_REGEX_MATCHES(street_fr_parts[0], R"(^\d{1,4}$)");
    EXPECT_TRUE(
        faker::testing::contains(location::data::france_street_prefixes, street_fr_parts[1]));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::france_street_suffixes,
        utils::join({ street_fr_parts.begin() + 2, street_fr_parts.end() }));

    const auto address_it = location::street_address(location::address_country::italy);
    EXPECT_TRUE(faker::testing::contains_any_of(address_it, person::data::italian_male_first_names)
        || faker::testing::contains_any_of(address_it, person::data::italian_female_first_names)
        || faker::testing::contains_any_of(address_it, person::data::italian_last_names));
    EXPECT_TRUE(faker::testing::contains_any_of(address_it, location::data::italy_street_prefixes));

    const auto address_in = location::street_address(location::address_country::india);
    const auto street_in_parts = utils::split(address_in, " ");
    EXPECT_GE(street_in_parts.size(), 3u);
    FAKER_EXPECT_REGEX_MATCHES(street_in_parts[0], R"(^\d+$)");
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::india_street_suffixes,
        utils::join({ street_in_parts.begin() + 2, street_in_parts.end() }));

    const auto address_sp = location::street_address(location::address_country::spain);
    EXPECT_TRUE(faker::testing::contains_any_of(address_sp, person::data::spanish_male_first_names)
        || faker::testing::contains_any_of(address_sp, person::data::spanish_female_first_names)
        || faker::testing::contains_any_of(address_sp, person::data::spanish_last_names));
    EXPECT_TRUE(faker::testing::contains_any_of(address_sp, location::data::spain_street_suffixes));

    const auto address_fi = location::street_address(location::address_country::finland);
    EXPECT_TRUE(faker::testing::contains_any_of(address_fi, person::data::finnish_male_first_names)
        || faker::testing::contains_any_of(address_fi, person::data::finnish_female_first_names)
        || faker::testing::contains_any_of(address_fi, person::data::finnish_last_names));
    EXPECT_TRUE(
        faker::testing::contains_any_of(address_fi, location::data::finland_street_suffixes));

    const auto address_au = location::street_address(location::address_country::australia);
    const auto address_au_parts = utils::split(address_au, " ");
    const auto& address_au_suffix
        = utils::join({ address_au_parts.begin() + 1, address_au_parts.end() });
    EXPECT_TRUE(faker::testing::contains_any_of(
                    address_au_suffix, person::data::australian_male_first_names)
        || faker::testing::contains_any_of(
            address_au_suffix, person::data::australian_female_first_names)
        || faker::testing::contains_any_of(address_au_suffix, person::data::australian_last_names)
        || faker::testing::contains_any_of(
            address_au_suffix, location::data::australia_street_suffixes));
    FAKER_EXPECT_REGEX_MATCHES(address_au_parts[0], R"(^\d{1,4}$)");

    const auto address_ru = location::street_address(location::address_country::russia);
    EXPECT_TRUE(
        faker::testing::contains_any_of(address_ru, location::data::russia_street_prefixes));
    EXPECT_TRUE(faker::testing::contains_any_of(address_ru, person::data::russian_male_first_names)
        || faker::testing::contains_any_of(address_ru, person::data::russian_male_last_names)
        || faker::testing::contains_any_of(address_ru, person::data::russian_female_first_names)
        || faker::testing::contains_any_of(address_ru, person::data::russian_female_last_names)
        || faker::testing::contains_any_of(address_ru, location::data::russia_street_names));
}

TEST_F(LocationTest, should_generate_country)
{
    const auto country = location::country_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::all_countries, country);
}

TEST_F(LocationTest, should_generate_country_code)
{
    const auto country_code = location::country_code();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::country_codes, country_code);
}

TEST_F(LocationTest, should_generate_latitude)
{
    const auto latitude_default_prec = location::latitude();
    FAKER_EXPECT_BETWEEN(std::stof(latitude_default_prec), -90, 90);
    FAKER_EXPECT_REGEX_MATCHES(latitude_default_prec, R"(^-?\d+\.\d{4}$)");

    const auto latitude_custom_prec = location::latitude(precision_t::three_dp);
    FAKER_EXPECT_BETWEEN(std::stof(latitude_custom_prec), -90, 90);
    FAKER_EXPECT_REGEX_MATCHES(latitude_custom_prec, R"(^-?\d+\.\d{3}$)");
}

TEST_F(LocationTest, should_generate_longitude)
{
    const auto longitude_default_prec = location::longitude();
    FAKER_EXPECT_BETWEEN(std::stof(longitude_default_prec), -180, 180);
    FAKER_EXPECT_REGEX_MATCHES(longitude_default_prec, R"(^-?\d+\.\d{4}$)");

    const auto longitude_custom_prec = location::longitude(precision_t::six_dp);
    FAKER_EXPECT_BETWEEN(std::stof(longitude_custom_prec), -180, 180);
    FAKER_EXPECT_REGEX_MATCHES(longitude_custom_prec, R"(^-?\d+\.\d{6}$)");
}

TEST_F(LocationTest, should_generate_direction)
{
    const auto direction = location::direction();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::directions, direction);
}

TEST_F(LocationTest, should_generate_time_zone)
{
    const auto time_zone = location::time_zone();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::time_zones, time_zone);
}
