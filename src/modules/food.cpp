#include "../common/random.h"
#include "food_data.h"
#include <faker/food.h>

namespace faker::food {

std::string_view alcoholic_beverage() { return random::element(data::alcoholicBeverages); }

std::string_view dish_name() { return random::element(data::dishNames); }

std::string_view category() { return random::element(data::foodCategories); }

std::string_view fruit() { return random::element(data::fruits); }

std::string_view grain() { return random::element(data::grains); }

std::string_view meat() { return random::element(data::meats); }

std::string_view milk_product() { return random::element(data::milkProducts); }

std::string_view non_alcoholic_beverage() { return random::element(data::nonalcoholicBeverages); }

std::string_view nut() { return random::element(data::nuts); }

std::string_view oil() { return random::element(data::oils); }

std::string_view seafood() { return random::element(data::seafoods); }

std::string_view seed() { return random::element(data::seeds); }

std::string_view sugar_product() { return random::element(data::sugarProducts); }

std::string_view vegetable() { return random::element(data::vegetables); }
}
