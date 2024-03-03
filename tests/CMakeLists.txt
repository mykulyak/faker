add_executable(
    test_faker
    bio_helper_test.cpp
    bio_helper.cpp
    json_helper.cpp
    common/conversions_test.cpp
    common/format_helper_test.cpp
    common/json_helper_test.cpp
    common/luhn_check_test.cpp
    common/precision_mapper_test.cpp
    common/strings_test.cpp
    modules/airline_test.cpp
    modules/animal_test.cpp
    modules/book_test.cpp
    modules/color_test.cpp
    modules/commerce_test.cpp
    modules/company_test.cpp
    modules/computer_test.cpp
    modules/crypto_test.cpp
    modules/database_test.cpp
    modules/datatype_test.cpp
    modules/date_test.cpp
    modules/finance_test.cpp
    modules/food_test.cpp
    modules/git_test.cpp
    modules/hacker_test.cpp
    modules/helper_test.cpp
    modules/image_test.cpp
    modules/internet_test.cpp
    modules/location_test.cpp
    modules/lorem_test.cpp
    modules/medicine_test.cpp
    modules/movie_test.cpp
    modules/music_test.cpp
    modules/number_test.cpp
    modules/person_test.cpp
    modules/phone_test.cpp
    modules/science_test.cpp
    modules/sport_test.cpp
    modules/string_test.cpp
    modules/structure_test.cpp
    modules/system_test.cpp
    modules/vehicle_test.cpp
    modules/video_game_test.cpp
    modules/weather_test.cpp
    modules/word_test.cpp
)
target_include_directories(test_faker PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)

if (NOT USE_CXX20)
target_include_directories(test_faker PRIVATE ${TCB_SPAN_INCLUDE_DIRS})
endif()

turn_on_warnings(test_faker)

target_link_libraries(
    test_faker 
    PRIVATE 
        faker
        GTest::gtest 
        GTest::gtest_main 
        GTest::gmock 
        GTest::gmock_main
)
add_test(NAME test_faker COMMAND test_faker)