#include "../common/random.h"
#include "phone_data.h"
#include <faker/phone.h>
#include <string>
#include <unordered_map>

namespace faker::phone {
namespace {
    std::unordered_map<phone_number_format_t, std::string_view> make_phone_number_format_map()
    {
        std::unordered_map<phone_number_format_t, std::string_view> result;
        // TODO this is brittle, because it depends on the assumption that order of elements in
        // PhoneNumberCountryFormat is the same as the one in data::number_formats
        for (auto i = static_cast<unsigned long>(phone_number_format_t::Default);
             i <= static_cast<unsigned long>(phone_number_format_t::Zimbabwe); i++) {
            result[static_cast<phone_number_format_t>(i)] = data::number_formats[i];
        }
        return result;
    }

    const std::unordered_map<phone_number_format_t, std::string_view> phone_number_format_map
        = make_phone_number_format_map();
}

std::string number(std::optional<std::string> format)
{
    auto final_format
        = format.has_value() ? *format : std::string(random::element(data::number_formats));
    return random::replace_symbol_with_number(final_format);
}

std::string number(phone_number_format_t format)
{
    std::string result { phone_number_format_map.at(
        phone_number_format_map.find(format) != phone_number_format_map.end()
            ? format
            : phone_number_format_t::Default) };
    return random::replace_symbol_with_number(result);
}

std::string imei() { return random::replace_credit_card_symbols("##-######-######-L", '#'); }

std::string_view platform() { return random::element(data::platforms); }

std::string_view model_name() { return random::element(data::model_names); }

std::string_view manufacturer() { return random::element(data::manufacturers); }

}
