#pragma once

#include <ranges>
#include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto fn = []<typename> {}>
	concept is_fwd_sized_range = std::ranges::forward_range<T> && std::ranges::sized_range<T> && xieite::is_satisfd<fn, std::ranges::range_value_t<T>>;;
}
