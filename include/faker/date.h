#ifndef FAKER_DATE_H
#define FAKER_DATE_H

#include <string>

namespace faker::date {
/**
 * @brief The format of the date, ISO 8601 or numerical timestamp.
 */
enum class date_format {
    iso,
    timestamp,
};

/**
 * @brief Generates a random date in the past.
 *
 * @param years The range of years the date may be in the past. Defaults to `1`.
 * @param format The format of the date. Defaults to `date_format::iso`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::past() // "2023-12-08T19:31:32Z"
 * date::past(5) // "2020-06-16T15:24:09Z"
 * date::past(5, date::date_format::iso) // "2020-06-16T15:24:09Z"
 * date::past(5, date::date_format::timestamp) // "1592321049"
 * @endcode
 */
std::string past(int years = 1, date_format format = date_format::iso);

/**
 * @brief Generates a random date in the future.
 *
 * @param years The range of years the date may be in the future. Defaults to `1`.
 * @param format The format of the date. Defaults to `date_format::iso`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::future() // "2023-09-27T09:47:46Z"
 * date::future(5) // "2024-06-11T19:46:29Z"
 * date::future(5, date::date_format::iso) // "2024-06-11T19:46:29Z"
 * date::future(5, date::date_format::timestamp) // "1718229989"
 * @endcode
 */
std::string future(int years = 1, date_format format = date_format::iso);

/**
 * @brief Generates a random date in the recent past.
 *
 * @param days The range of days the date may be in the past. Defaults to `3`.
 * @param format The format of the date. Defaults to `date_format::iso`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::recent() // "2023-07-05T14:12:40Z"
 * date::recent(10) // "2023-06-29T18:24:12Z"
 * date::recent(10, date::date_format::iso) // "2023-06-29T18:24:12Z"
 * date::recent(10, date::date_format::timestamp) // "1718229989"
 * @endcode
 */
std::string recent(int days = 3, date_format format = date_format::iso);

/**
 * @brief Generates a random date in the soon future.
 *
 * @param days The range of days the date may be in the future. Defaults to `3`.
 * @param format The format of the date. Defaults to `date_format::iso`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::soon() // "2023-07-07T18:19:12Z"
 * date::soon(10) // "2023-07-15T09:59:11Z"
 * date::soon(10, date::date_format::iso) // "2023-07-15T09:59:11Z"
 * date::soon(10, date::date_format::timestamp) // "1718229989"
 * @endcode
 */
std::string soon(int days = 3, date_format format = date_format::iso);

/**
 * @brief Generates a random birthdate by age.
 *
 * @param min_age The minimum age to generate a birthdate. Defaults to `18`.
 * @param max_age The maximum age to generate a birthdate. Defaults to `80`.
 * @param format The format of the date. Defaults to `date_format::iso`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::birthdate_by_age() // "2002-12-07T23:20:12Z"
 * date::birthdate_by_age(20, 30) // "1996-11-14T11:27:09Z"
 * date::birthdate_by_age(20, 30, date::date_format::iso) // "1996-11-14T11:27:09Z"
 * date::birthdate_by_age(20, 30, date::date_format::timestamp) // "1718229989"
 * @endcode
 */
std::string birthdate_by_age(
    unsigned min_age = 18, unsigned max_age = 80, date_format format = date_format::iso);

/**
 * @brief Generates a random birthdate by year.
 *
 * @param min_year The minimum year to generate a birthdate. Defaults to `1920`.
 * @param max_year The maximum year to generate a birthdate. Defaults to `2000`.
 * @param format The format of the date. Defaults to `date_format::iso`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::birthdate_by_year() // "1965-02-19T02:19:47Z"
 * date::birthdate_by_year(1996, 1996) // "1996-05-19T12:00:23Z"
 * date::birthdate_by_year(1996, 1996, date::date_format::iso) // "1996-05-19T12:00:23Z"
 * date::birthdate_by_year(1996, 1996, date::date_format::timestamp) // "1718229989"
 * @endcode
 */
std::string birthdate_by_year(
    unsigned min_year = 1920, unsigned max_year = 2000, date_format format = date_format::iso);

/**
 * @brief Returns a name of random day of the week.
 *
 * @returns Name of the weekday.
 *
 * @code
 * date::weekday_name() // "Monday"
 * @endcode
 */
std::string_view weekday_name();

/**
 * @brief Returns an abbreviated name of random day of the week.
 *
 * @returns Abbreviated name of the weekday.
 *
 * @code
 * date::weekday_abbr_name() // "Mon"
 * @endcode
 */
std::string_view weekday_abbr_name();

/**
 * @brief Returns a random name of a month.
 *
 * @returns Name of the month.
 *
 * @code
 * date::month_name() // "October"
 * @endcode
 */
std::string_view month_name();

/**
 * @brief Returns an abbreviated name of random month.
 *
 * @returns Abbreviated name of the month.
 *
 * @code
 * date::month_abbr_name() // "Feb"
 * @endcode
 */
std::string_view month_abbr_name();
}

#endif