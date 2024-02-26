#include "airline_data.h"
#include <faker/airline.h>
#include <faker/helper.h>
#include <faker/number.h>
#include <faker/string.h>
#include <string>

namespace faker::airline {
std::string_view aircraftType() { return Helper::arrayElement(data::aircraftTypes); }

Airplane airplane() { return Helper::arrayElement(data::airplanes); }

AirlineStruct airline() { return Helper::arrayElement<faker::AirlineStruct>(data::airlines); }

Airport airport() { return Helper::arrayElement(data::airports); }

std::string seat(faker::AircraftType aircraftType)
{
    return std::to_string(number::integer(1, data::aircraftTypeMaxRows.at(aircraftType)))
        + Helper::arrayElement(data::aircraftTypeSeatLetters.at(aircraftType));
}

std::string recordLocator(bool allowNumerics)
{
    if (allowNumerics) {
        return string::alphanumeric(6, StringCasing::Upper);
    }

    return string::alpha(6, StringCasing::Upper);
}

std::string flightNumber(bool addLeadingZeros, unsigned int length)
{
    if (addLeadingZeros) {
        return string::numeric(length, true);
    }

    return string::numeric(length, false);
}

std::string flightNumberByRange(bool addLeadingZeros, faker::Range length)
{
    if (addLeadingZeros) {
        return string::numeric(number::integer(length.min, length.max), true);
    }

    return string::numeric(number::integer(length.min, length.max), false);
}
}
