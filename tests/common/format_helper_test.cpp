#include "../test_helpers.h"
#include <common/formatter.h>
#include <stdexcept>

using namespace faker;

namespace {
struct TokenGeneratorNotFoundError : std::runtime_error {
    using std::runtime_error::runtime_error;
};
}

TEST(FormatHelperTest, should_fill_format_tokens_data)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    const auto result = utils::fill_token_values(format, [](std::string_view token) {
        if (token == "hello") {
            return "library";
        } else if (token == "faker") {
            return "cxx";
        } else if (token == "cxx") {
            return "faker";
        } else if (token == "library") {
            return "hello";
        } else {
            return "";
        }
    });

    EXPECT_EQ(result, "library cxx-faker hello");
}

TEST(FormatHelperTest, should_throw_when_token_generator_not_found)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    EXPECT_THROW(utils::fill_token_values(format,
        [](std::string_view token) {
            if (token == "hello") {
                return "library";
            } else if (token == "faker") {
                return "cxx";
            } else if (token == "cxx") {
                return "faker";
            } else {
                throw TokenGeneratorNotFoundError { utils::format(
                    "Generator not found for token {}.", token) };
            }
        });
                 , TokenGeneratorNotFoundError);
}

TEST(FormatHelperTest, should_support_string_formatting)
{
    EXPECT_EQ(utils::format("{}", 1), "1");
    EXPECT_EQ(utils::format("{} {}", "Hello", "World"), "Hello World");
    EXPECT_EQ(utils::format("{0} {1}", "Hello", "World"), "Hello World");
}