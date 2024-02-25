#ifndef FAKER_TYPES_COUNTRY_H
#define FAKER_TYPES_COUNTRY_H

#include <array>
#include <string_view>

namespace faker {
enum class Country {
    Usa,
    Poland,
    France,
    Germany,
    Italy,
    Russia,
    England,
    Romania,
    India,
    Finland,
    Nepal,
    Spain,
    Turkey,
    Czech,
    Slovakia,
    Ukraine,
    Denmark,
    Sweden,
    Brazil,
    Norway,
    Japan,
    Portugal,
    Hungary,
    Croatia,
    Greece,
    Slovenia,
    Austria,
    Switzerland,
    Belgium,
    Netherlands,
    China,
    Korea,
    Canada,
    Mexico,
    Argentina,
    Australia,
    Serbia,
    Macedonia,
    Albania,
    Latvia,
    Ireland,
    Belarus,
    Estonia,
    Iran,
    Bulgaria,
    Moldova,
    Lithuania,
    Iceland,
    Palestine,
    Israel,
    Vietnam,
    Monaco,
    Bosnia,
    Lebanon,
    Syria,
    Malta,
    SouthAfrica,
    Azerbaijan,
    Ghana,
    Kazakhstan,
    Maldives,
};

extern const std::array<Country, 61> countries;
std::string_view toString(Country country);
}

#endif