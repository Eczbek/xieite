#pragma once

#include <ranges>
#include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_input_range = std::ranges::input_range<T> && xieite::is_satisfd<fn, std::ranges::range_value_t<T>>;
}
