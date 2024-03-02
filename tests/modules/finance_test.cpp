#include "../test_helpers.h"
#include <algorithm>
#include <charconv>
#include <common/luhn_check.h>
#include <common/strings.h>
#include <faker/finance.h>
#include <gmock/gmock.h>
#include <modules/finance_data.h>
#include <modules/string_data.h>
#include <ranges>
#include <regex>
#include <unordered_set>

using namespace ::testing;
using namespace faker;

namespace {
const std::string_view credit_card_chars = "0123456789-";

const std::unordered_map<finance::iban_country, std::string> iban_country_regex {
    { finance::iban_country::austria, "^(AT)([0-9]{2})([0-9]{5})([0-9]{11})$" },
    { finance::iban_country::belgium, "^(BE)([0-9]{2})([0-9]{3})([0-9]{7})([0-9]{2})$" },
    { finance::iban_country::bulgaria,
        "^(BG)([0-9]{2})([A-Z]{4})([0-9]{4})([0-9]{2})([a-zA-Z0-9]{8})$" },
    { finance::iban_country::croatia, "^(HR)([0-9]{2})([0-9]{7})([0-9]{10})$" },
    { finance::iban_country::cyprus, "^(CY)([0-9]{2})([0-9]{3})([0-9]{5})([a-zA-Z0-9]{16})$" },
    { finance::iban_country::czechia, "^(CZ)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$" },
    { finance::iban_country::denmark, "^(DK)([0-9]{2})([0-9]{4})([0-9]{9})([0-9]{1})$" },
    { finance::iban_country::estonia, "^(EE)([0-9]{2})([0-9]{2})([0-9]{2})([0-9]{11})([0-9]{1})$" },
    { finance::iban_country::finland, "^(FI)([0-9]{2})([0-9]{6})([0-9]{7})([0-9]{1})$" },
    { finance::iban_country::france,
        "^(FR)([0-9]{2})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{11})([0-9]{2})$" },
    { finance::iban_country::germany, "^(DE)([0-9]{2})([0-9]{8})([0-9]{10})$" },
    { finance::iban_country::greece, "^(GR)([0-9]{2})([0-9]{3})([0-9]{4})([a-zA-Z0-9]{16})$" },
    { finance::iban_country::hungary,
        "^(HU)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{15})([0-9]{1})$" },
    { finance::iban_country::ireland, "^(IE)([0-9]{2})([A-Z]{4})([0-9]{6})([0-9]{8})$" },
    { finance::iban_country::italy,
        "^(IT)([0-9]{2})([A-Z]{1})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{12})$" },
    { finance::iban_country::latvia, "^(LV)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{13})$" },
    { finance::iban_country::lithuania, "^(LT)([0-9]{2})([0-9]{5})([0-9]{11})$" },
    { finance::iban_country::luxembourg, "^(LU)([0-9]{2})([0-9]{3})([a-zA-Z0-9]{13})$" },
    { finance::iban_country::malta, "^(MT)([0-9]{2})([A-Z]{4})([0-9]{5})([a-zA-Z0-9]{18})$" },
    { finance::iban_country::netherlands, "^(NL)([0-9]{2})([A-Z]{4})([0-9]{10})$" },
    { finance::iban_country::poland, "^(PL)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{16})$" },
    { finance::iban_country::portugal,
        "^(PT)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{11})([0-9]{2})$" },
    { finance::iban_country::romania, "^(RO)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{16})$" },
    { finance::iban_country::slovakia, "^(SK)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$" },
    { finance::iban_country::slovenia, "^(SI)([0-9]{2})([0-9]{2})([0-9]{3})([0-9]{8})([0-9]{2})$" },
    { finance::iban_country::spain, "^(ES)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{2})([0-9]{10})$" },
    { finance::iban_country::sweden, "^(SE)([0-9]{2})([0-9]{3})([0-9]{17})$" },
};

const std::unordered_map<finance::iban_country, std::string> iban_country_test_names {
    { finance::iban_country::austria, "shouldGenerateAustriaIban" },
    { finance::iban_country::belgium, "shouldGenerateBelgiumIban" },
    { finance::iban_country::bulgaria, "shouldGenerateBulgariaIban" },
    { finance::iban_country::croatia, "shouldGenerateCroatiaIban" },
    { finance::iban_country::cyprus, "shouldGenerateCyprusIban" },
    { finance::iban_country::czechia, "shouldGenerateCzechiaIban" },
    { finance::iban_country::denmark, "shouldGenerateDenmarkIban" },
    { finance::iban_country::estonia, "shouldGenerateEstoniaIban" },
    { finance::iban_country::finland, "shouldGenerateFinlandIban" },
    { finance::iban_country::france, "shouldGenerateFranceIban" },
    { finance::iban_country::germany, "shouldGenerateGermanyIban" },
    { finance::iban_country::greece, "shouldGenerateGreeceIban" },
    { finance::iban_country::hungary, "shouldGenerateHungaryIban" },
    { finance::iban_country::ireland, "shouldGenerateIrelandIban" },
    { finance::iban_country::italy, "shouldGenerateItalyIban" },
    { finance::iban_country::latvia, "shouldGenerateLatviaIban" },
    { finance::iban_country::lithuania, "shouldGenerateLithuaniaIban" },
    { finance::iban_country::luxembourg, "shouldGenerateLuxembourgIban" },
    { finance::iban_country::malta, "shouldGenerateMaltaIban" },
    { finance::iban_country::netherlands, "shouldGenerateNetherlandsIban" },
    { finance::iban_country::poland, "shouldGeneratePolandIban" },
    { finance::iban_country::portugal, "shouldGeneratePortugalIban" },
    { finance::iban_country::romania, "shouldGenerateRomaniaIban" },
    { finance::iban_country::slovakia, "shouldGenerateSlovakiaIban" },
    { finance::iban_country::slovenia, "shouldGenerateSloveniaIban" },
    { finance::iban_country::spain, "shouldGenerateSpainIban" },
    { finance::iban_country::sweden, "shouldGenerateSwedenIban" },
};

const std::unordered_map<finance::bic_country, std::string> bic_country_test_names {
    { finance::bic_country::poland, "shouldGeneratePolandBic" },
    { finance::bic_country::usa, "shouldGenerateUnitedStatesBic" },
    { finance::bic_country::england, "shouldGenerateUnitedKingdomBic" },
    { finance::bic_country::germany, "shouldGenerateGermanyBic" },
    { finance::bic_country::romania, "shouldGenerateRomaniaBic" },
    { finance::bic_country::france, "shouldGenerateFranceBic" },
    { finance::bic_country::italy, "shouldGenerateItalyBic" },
    { finance::bic_country::spain, "shouldGenerateSpainBic" },
    { finance::bic_country::netherlands, "shouldGenerateNetherlandsBic" },
    { finance::bic_country::india, "shouldGenerateIndiaBic" },
};

bool contains_only_digits(const std::string& data)
{
    return faker::testing::all_of(
        data, [](char ch) { return faker::testing::contains(string::data::digits, ch); });
}

bool contains_only_valid_credit_card_chars(const std::string& data)
{
    return faker::testing::all_of(
        data, [](char ch) { return faker::testing::contains(credit_card_chars, ch); });
}

std::unordered_set<finance::iban_country> prepare_iban_countries_keys()
{
    std::unordered_set<finance::iban_country> result;
    for (const auto& [ibanCountry, _] : iban_country_regex) {
        result.insert(ibanCountry);
    }
    return result;
}

std::unordered_set<finance::iban_country> iban_countries_keys = prepare_iban_countries_keys();

const std::vector<std::string_view> valid_iban_prefixes { "AT", "BE", "BG", "HR", "CY", "CZ", "DK",
    "EE", "FI", "FR", "DE", "GR", "HU", "IE", "IT", "LV", "LT", "LU", "MT", "NL", "PL", "PT", "RO",
    "SK", "SI", "ES", "SE" };

const std::vector<std::string_view> valid_discover_cc_prefixes = { "34", "37", "51", "52", "53",
    "54", "55", "6771-89", "4", "6011", "65", "644", "645", "646", "647", "648", "649", "6011-62" };
const std::vector<std::string_view> valid_mastercard_cc_prefixes
    = { "51", "52", "53", "54", "55", "6771-89" };

const std::string_view valid_bitcoin_address_chars {
    "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789"
};

const std::string valid_litecoin_address_chars {
    "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789"
};

}

class FinanceTest : public TestWithParam<finance::iban_country> { };

TEST_F(FinanceTest, should_generate_currency)
{
    const auto currency = finance::currency();

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::currencies, currency);
}

TEST_F(FinanceTest, should_generate_currency_name)
{
    const auto currency_name = finance::currency_name();

    EXPECT_TRUE(faker::testing::any_of(finance::data::currencies,
        [=](const finance::currency_info& currency) { return currency.name == currency_name; }));
}

TEST_F(FinanceTest, should_generate_currency_code)
{
    const auto currency_code = finance::currency_code();

    EXPECT_TRUE(faker::testing::any_of(finance::data::currencies,
        [=](const finance::currency_info& currency) { return currency.code == currency_code; }));
}

TEST_F(FinanceTest, should_generate_currency_symbol)
{
    const auto currency_symbol = finance::currency_symbol();

    EXPECT_TRUE(faker::testing::any_of(
        finance::data::currencies, [=](const finance::currency_info& currency) {
            return currency.symbol == currency_symbol;
        }));
}

TEST_F(FinanceTest, should_generate_account_type)
{
    const auto account_type = finance::account_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::account_types, account_type);
}

TEST_F(FinanceTest, should_generate_amount)
{
    const auto amount = finance::amount();

    const auto amount_parts = utils::split(amount, ".");
    EXPECT_EQ(amount_parts.size(), 2);
    EXPECT_EQ(amount_parts[1].size(), 2);

    FAKER_EXPECT_BETWEEN(std::stof(amount.data()), 0, 1000);
}

/*
 * The default GTest macro "MatchesRegex" has only minimal support on
 * windows. Hence, we define our own macro which uses the c++ default
 * implementation of the used compiler.
 */
MATCHER_P(MatchesRegexCpp, value, "") { return std::regex_match(arg, std::regex(value)); }

TEST_P(FinanceTest, should_check_iban_generator)
{
    auto iban_country = GetParam();

    EXPECT_THAT(finance::iban(iban_country), MatchesRegexCpp(iban_country_regex.at(iban_country)));
}

INSTANTIATE_TEST_SUITE_P(TestIbanGenerator, FinanceTest,
    ValuesIn(iban_countries_keys.begin(), iban_countries_keys.end()),
    [](const TestParamInfo<finance::iban_country>& info) {
        return iban_country_test_names.at(info.param);
    });

TEST_F(FinanceTest, should_generate_amount_with_symbol)
{
    const auto amount = finance::amount(150, 450, precision_t::four_dp, "$");

    FAKER_EXPECT_STRING_STARTS_WITH(amount, "$");

    const auto amount_parts = utils::split(amount, ".");
    EXPECT_EQ(amount_parts.size(), 2);
    EXPECT_EQ(amount_parts[1].size(), 4);

    FAKER_EXPECT_BETWEEN(std::stof(amount.substr(1)), 150, 450);
}

TEST_F(FinanceTest, should_generate_iban)
{
    const auto iban = finance::iban();

    EXPECT_TRUE(faker::testing::any_of(valid_iban_prefixes,
        [&](std::string_view prefix) { return faker::testing::starts_with(iban, prefix); }));
}

TEST_F(FinanceTest, should_generate_account_number)
{
    const auto account_number_with_default_len = finance::account_number();
    const auto account_number_with_custom_len = finance::account_number(26);

    EXPECT_EQ(account_number_with_default_len.size(), 8);
    EXPECT_TRUE(contains_only_digits(account_number_with_default_len));

    EXPECT_EQ(account_number_with_custom_len.size(), 26);
    EXPECT_TRUE(contains_only_digits(account_number_with_custom_len));
}

TEST_F(FinanceTest, should_generate_pin_number)
{
    const auto pin_with_default_len = finance::pin();
    const auto pin_with_custom_len = finance::pin(8);

    EXPECT_EQ(pin_with_default_len.size(), 4);
    EXPECT_TRUE(contains_only_digits(pin_with_default_len));

    EXPECT_EQ(pin_with_custom_len.size(), 8);
    EXPECT_TRUE(contains_only_digits(pin_with_custom_len));
}

TEST_F(FinanceTest, should_generate_routing_number)
{
    const auto routing_number = finance::routing_number();

    EXPECT_EQ(routing_number.size(), 9);
    EXPECT_TRUE(contains_only_digits(routing_number));
}

TEST_F(FinanceTest, should_generate_credit_card_number)
{
    const auto any_cc_number = finance::credit_card_number();
    const auto amex_cc_number
        = finance::credit_card_number(finance::credit_card_type::american_express);
    const auto discover_cc_number
        = finance::credit_card_number(finance::credit_card_type::discover);
    const auto mastercard_cc_number
        = finance::credit_card_number(finance::credit_card_type::mastercard);
    const auto visa_cc_number = finance::credit_card_number(finance::credit_card_type::visa);

    EXPECT_TRUE(contains_only_valid_credit_card_chars(any_cc_number));
    EXPECT_TRUE(utils::luhn_check(any_cc_number));

    EXPECT_TRUE(faker::testing::starts_with(amex_cc_number, "34")
        || faker::testing::starts_with(amex_cc_number, "37"));
    EXPECT_TRUE(contains_only_valid_credit_card_chars(amex_cc_number));
    EXPECT_TRUE(utils::luhn_check(amex_cc_number));

    EXPECT_TRUE(faker::testing::starts_with_any_of(discover_cc_number, valid_discover_cc_prefixes));
    EXPECT_TRUE(contains_only_valid_credit_card_chars(discover_cc_number));
    EXPECT_TRUE(utils::luhn_check(discover_cc_number));

    EXPECT_TRUE(
        faker::testing::starts_with_any_of(mastercard_cc_number, valid_discover_cc_prefixes));
    EXPECT_TRUE(contains_only_valid_credit_card_chars(mastercard_cc_number));
    EXPECT_TRUE(utils::luhn_check(mastercard_cc_number));

    FAKER_EXPECT_STRING_STARTS_WITH(visa_cc_number, "4");
    EXPECT_TRUE(contains_only_valid_credit_card_chars(visa_cc_number));
    EXPECT_TRUE(utils::luhn_check(visa_cc_number));
}

TEST_F(FinanceTest, should_generate_credit_card_cvv)
{
    const auto cvv = finance::credit_card_cvv();

    EXPECT_EQ(cvv.size(), 3);
    EXPECT_TRUE(contains_only_digits(cvv));
}

TEST_F(FinanceTest, should_generate_bitcoin_address)
{
    const auto bitcoin_address = finance::bitcoin_address();

    FAKER_EXPECT_BETWEEN(bitcoin_address.size(), 27, 34);

    EXPECT_TRUE(faker::testing::starts_with(bitcoin_address, "1")
        || faker::testing::starts_with(bitcoin_address, "3"));
    EXPECT_TRUE(faker::testing::all_of(bitcoin_address,
        [](char ch) { return valid_bitcoin_address_chars.find(ch) != std::string::npos; }));
}

TEST_F(FinanceTest, should_generate_litecoin_address)
{
    const auto litecoin_address = finance::litecoin_address();

    FAKER_EXPECT_BETWEEN(litecoin_address.size(), 27, 34);

    EXPECT_TRUE(faker::testing::starts_with(litecoin_address, "L")
        || faker::testing::starts_with(litecoin_address, "M")
        || faker::testing::starts_with(litecoin_address, "3"));
    EXPECT_TRUE(faker::testing::all_of(litecoin_address,
        [](char ch) { return valid_litecoin_address_chars.find(ch) != std::string::npos; }));
}

TEST_F(FinanceTest, should_generate_ethereum_address)
{
    const auto ethereum_address = finance::ethereum_address();

    EXPECT_EQ(ethereum_address.size(), 42);
    EXPECT_EQ(ethereum_address.substr(0, 2), "0x");
    EXPECT_TRUE(faker::testing::any_of(ethereum_address.substr(2),
        [](char ch) { return string::data::hex_lower_digits.find(ch) != std::string::npos; }));
}

TEST_F(FinanceTest, should_generate_expiration_date)
{
    const auto expiration_date = finance::credit_card_expiration_date();

    int tenth_place_year = std::stoi(expiration_date.substr(3, 2));
    EXPECT_TRUE(tenth_place_year >= 24);
}

class FinanceBicTest : public TestWithParam<finance::bic_country> { };

TEST_P(FinanceBicTest, should_check_bic_generator)
{
    const auto country = GetParam();

    const auto bic = finance::bic(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::bic_countries_codes.at(country), bic);
}

INSTANTIATE_TEST_SUITE_P(TestBicGenerator, FinanceBicTest,
    Values(finance::bic_country::poland, finance::bic_country::usa, finance::bic_country::england,
        finance::bic_country::germany, finance::bic_country::romania, finance::bic_country::france,
        finance::bic_country::italy, finance::bic_country::spain, finance::bic_country::netherlands,
        finance::bic_country::india),
    [](const TestParamInfo<finance::bic_country>& info) {
        return bic_country_test_names.at(info.param);
    });
