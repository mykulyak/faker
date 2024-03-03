#include "../test_helpers.h"
#include <algorithm>
#include <chrono>
#include <faker/date.h>
#include <iomanip>
#include <modules/date_data.h>

#ifdef _WIN32
#define timegm _mkgmtime
#endif

using namespace ::testing;
using namespace faker;

namespace {
const auto seconds_per_year = 31556926;
const auto hours_per_day = 24;
const auto days_per_year = 365;

std::tm iso_string_to_tm(const std::string& iso_datetime_str)
{
    std::tm tm {};
    std::istringstream stream(iso_datetime_str);
    stream >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
    return tm;
}

std::chrono::time_point<std::chrono::system_clock,
    std::chrono::duration<int64_t, std::ratio<1, 1000000000>>>
iso_string_to_time_point(const std::string& iso_datetime_str)
{
    auto datetime = iso_string_to_tm(iso_datetime_str);
    return std::chrono::system_clock::from_time_t(timegm(&datetime));
}

template <typename TimePointT1, typename TimePointT2>
std::chrono::seconds::rep distance_in_seconds(const TimePointT1& start, const TimePointT2& end)
{
    return std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
}

std::chrono::system_clock::time_point timestamp_to_time_point(const std::string& ts_str)
{
    return std::chrono::system_clock::from_time_t(std::stoi(ts_str));
}

std::tm timestamp_string_to_tm(const std::string& ts_str)
{
    auto time_point = timestamp_to_time_point(ts_str);
    std::time_t time = std::chrono::system_clock::to_time_t(time_point);
    return *std::localtime(&time);
}

}

TEST(DateTest, should_generate_past_date_iso)
{
    auto date_iso_str = date::past();
    auto date_timestamp_str = date::past(1, date::date_format::timestamp);

    auto now = std::chrono::system_clock::now();

    auto iso_time_point = iso_string_to_time_point(date_iso_str);
    EXPECT_LT(distance_in_seconds(now, iso_time_point), seconds_per_year);
    EXPECT_LT(iso_time_point, now);

    auto timestamp_time_point = timestamp_to_time_point(date_timestamp_str);
    EXPECT_LT(distance_in_seconds(now, timestamp_time_point), seconds_per_year);
    EXPECT_LT(timestamp_time_point, now);
}

TEST(DateTest, should_generate_recent_date)
{
    auto date_iso_str = date::recent(5);
    auto date_timestamp_str = date::recent(10, date::date_format::timestamp);

    auto now = std::chrono::system_clock::now();

    auto iso_time_point = iso_string_to_time_point(date_iso_str);
    EXPECT_LT(distance_in_seconds(now, iso_time_point), seconds_per_year);
    EXPECT_LT(iso_time_point, now);

    auto timestamp_time_point = timestamp_to_time_point(date_timestamp_str);
    EXPECT_LT(distance_in_seconds(now, timestamp_time_point), seconds_per_year);
    EXPECT_LT(timestamp_time_point, now);
}

TEST(DateTest, should_generate_future_date)
{
    auto date_iso_str = date::future();
    auto date_timestamp_str = date::future(1, date::date_format::timestamp);

    auto now = std::chrono::system_clock::now();

    auto iso_time_point = iso_string_to_time_point(date_iso_str);
    EXPECT_LT(distance_in_seconds(iso_time_point, now), seconds_per_year);
    EXPECT_GT(iso_time_point, now);

    auto timestamp_time_point = timestamp_to_time_point(date_timestamp_str);
    EXPECT_LT(distance_in_seconds(timestamp_time_point, now), seconds_per_year);
    EXPECT_GT(timestamp_time_point, now);
}

TEST(DateTest, should_generate_soon_date)
{
    auto date_iso_str = date::soon(12);
    auto date_timestamp_str = date::soon(25, date::date_format::timestamp);

    auto now = std::chrono::system_clock::now();

    auto iso_time_point = iso_string_to_time_point(date_iso_str);
    EXPECT_LT(distance_in_seconds(iso_time_point, now), seconds_per_year);
    EXPECT_GT(iso_time_point, now);

    auto timestamp_time_point = timestamp_to_time_point(date_timestamp_str);
    EXPECT_LT(distance_in_seconds(timestamp_time_point, now), seconds_per_year);
    EXPECT_GT(timestamp_time_point, now);
}

TEST(DateTest, should_generate_birth_date_by_age)
{
    auto date_iso_str = date::birthdate_by_age(5, 15);
    auto date_timestamp_str = date::birthdate_by_age(5, 15, date::date_format::timestamp);

    auto now = std::chrono::system_clock::now();
    auto expected_start_point = now - std::chrono::hours { 15 * days_per_year * hours_per_day };
    auto expected_end_point = now - std::chrono::hours { 5 * days_per_year * hours_per_day };

    FAKER_EXPECT_BETWEEN(
        iso_string_to_time_point(date_iso_str), expected_start_point, expected_end_point);
    FAKER_EXPECT_BETWEEN(
        timestamp_to_time_point(date_timestamp_str), expected_start_point, expected_end_point);
}

TEST(DateTest, should_generate_birth_date_by_exact_year)
{
    auto date_iso_str = date::birthdate_by_year(1996, 1996);
    auto date_timestamp_str = date::birthdate_by_year(1996, 1996, date::date_format::timestamp);

    EXPECT_EQ(iso_string_to_tm(date_iso_str).tm_year, 96);
    EXPECT_EQ(timestamp_string_to_tm(date_timestamp_str).tm_year, 96);
}

TEST(DateTest, should_generate_birth_date_by_year_range)
{
    auto date_iso_str = date::birthdate_by_year(1990, 2000);
    auto date_timestamp_str = date::birthdate_by_year(1990, 2000, date::date_format::timestamp);

    FAKER_EXPECT_BETWEEN(iso_string_to_tm(date_iso_str).tm_year, 90, 100);
    FAKER_EXPECT_BETWEEN(timestamp_string_to_tm(date_timestamp_str).tm_year, 90, 100);
}

TEST(DateTest, should_generate_weekday_name)
{
    auto generatedWeekdayName = date::weekday_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(date::data::weekday_names, generatedWeekdayName);
}

TEST(DateTest, should_generate_weekday_abbreviated_name)
{
    auto month_abbr = date::weekday_abbr_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(date::data::weekday_abbr_names, month_abbr);
}

TEST(DateTest, should_generate_month_name)
{
    auto month_name = date::month_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(date::data::month_names, month_name);
}

TEST(DateTest, should_generate_month_abbreviated_name)
{
    auto month_abbr = date::month_abbr_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(date::data::month_abbr_names, month_abbr);
}
