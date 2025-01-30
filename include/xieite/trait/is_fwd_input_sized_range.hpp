#pragma once

#include <ranges>
#include "../trait/is_fwd_input_range.hpp"
#include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_fwd_input_sized_range = xieite::is_fwd_input_range<T> && std::ranges::sized_range<T> && xieite::is_satisfd<fn, std::ranges::range_value_t<T>>;;
}
