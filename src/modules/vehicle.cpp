#include "../common/formatter.h"
#include "../common/random.h"
#include "vehicle_data.h"
#include <faker/number.h>
#include <faker/string.h>
#include <faker/vehicle.h>

namespace faker::vehicle {

std::string_view bicycle() { return random::element(data::bicycle_types); }

std::string_view color() { return random::element(data::vehicle_colors); }

std::string_view fuel() { return random::element(data::fuel_types); }

std::string_view manufacturer() { return random::element(data::manufacturers); }

std::string_view model() { return random::element(data::models); }

std::string_view type() { return random::element(data::vehicle_types); }

std::string vehicle() { return utils::format("{} {}", manufacturer(), model()); }

std::string vin()
{
    std::string exclude_characters { "oiqOIQ" };

    return utils::format("{}{}{}{}",
        string::alphanumeric(10, string::StringCasing::Upper, exclude_characters),
        string::alpha(1, string::StringCasing::Upper, exclude_characters),
        string::alphanumeric(1, string::StringCasing::Upper, exclude_characters),
        number::integer(10000, 99999));
}

std::string vrm()
{
    return utils::format("{}{}{}", string::alpha(2, string::StringCasing::Upper),
        string::numeric(2, true), string::alpha(3, string::StringCasing::Upper));
}

}
