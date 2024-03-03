#include "../json_helper.h"
#include "../test_helpers.h"
#include <common/strings.h>
#include <faker/structure.h>
#include <modules/airline_data.h>
#include <modules/animal_data.h>
#include <modules/book_data.h>
#include <modules/movie_data.h>
#include <unordered_map>
#include <unordered_set>

using namespace faker;

TEST(StructureTest, should_generate_json)
{
    std::vector<structure::structure_token_spec> specs;
    specs.push_back(structure::structure_token_spec {
        "Airport name", structure::structure_token_t::airline_airport_name });
    specs.push_back(
        structure::structure_token_spec { "Bird name", structure::structure_token_t::animal_bird });
    specs.push_back(
        structure::structure_token_spec { "Book title", structure::structure_token_t::book_title });
    specs.push_back(structure::structure_token_spec {
        "Actor name", structure::structure_token_t::movie_actor });

    const auto json_str = structure::json(specs);

    const auto parsed_json = faker::testing::simple_json_parser(json_str);

    auto value1 = parsed_json.find("Airport name")->second;
    auto value2 = parsed_json.find("Bird name")->second;
    auto value3 = parsed_json.find("Book title")->second;
    auto value4 = parsed_json.find("Actor name")->second;

    EXPECT_TRUE(faker::testing::any_of(
        airline::data::airports, [value1](auto& airport) { return airport.name == value1; }));
    FAKER_EXPECT_CONTAINER_CONTAINS(animal::data::birds, value2);
    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::titles, value3);
    FAKER_EXPECT_CONTAINER_CONTAINS(movie::data::actors, value4);
}

TEST(StructureTest, should_generate_csv)
{
    std::vector<structure::structure_token_spec> specs;
    specs.push_back(structure::structure_token_spec {
        "Airport name", structure::structure_token_t::airline_airport_name });
    specs.push_back(
        structure::structure_token_spec { "Bird name", structure::structure_token_t::animal_bird });
    specs.push_back(
        structure::structure_token_spec { "Book title", structure::structure_token_t::book_title });
    specs.push_back(structure::structure_token_spec {
        "Actor name", structure::structure_token_t::movie_actor });

    const unsigned row_count = 2;
    const auto generated_csv = structure::csv(specs, row_count);

    std::istringstream stream(generated_csv);
    std::string line;

    std::getline(stream, line);

    auto line_parts = utils::split(line, ",");
    std::unordered_set<std::string_view> keys { line_parts.begin(), line_parts.end() };

    ASSERT_TRUE(keys.find("Actor name") != keys.end());
    ASSERT_TRUE(keys.find("Airport name") != keys.end());
    ASSERT_TRUE(keys.find("Bird name") != keys.end());
    ASSERT_TRUE(keys.find("Book title") != keys.end());

    unsigned lines_read = 0;
    while (std::getline(stream, line)) {
        EXPECT_TRUE(faker::testing::any_of(movie::data::actors,
            [&line](const auto& actor) { return line.find(actor) != std::string::npos; }));
        EXPECT_TRUE(faker::testing::any_of(airline::data::airports,
            [&line](auto& airport) { return line.find(airport.name) != std::string::npos; }));
        EXPECT_TRUE(faker::testing::any_of(animal::data::birds,
            [&line](const auto& bird) { return line.find(bird) != std::string::npos; }));
        EXPECT_TRUE(faker::testing::any_of(book::data::titles,
            [&line](const auto& title) { return line.find(title) != std::string::npos; }));
        ++lines_read;
    }

    EXPECT_EQ(lines_read, row_count);
}
