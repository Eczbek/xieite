#pragma once

#include <ranges>
#include "../trait/isfwd_input_range.hpp"
#include "../trait/issatisfd.hpp"

namespace x4 {
	template<typename T, auto fn = []<typename> {}>
	concept isfwdiszrange = x4::isfwd_input_range<T> && std::ranges::sized_range<T> && x4::issatisfd<fn, std::ranges::range_value_t<T>>;;
}
