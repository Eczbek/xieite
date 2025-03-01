#pragma once

#include <ranges>
#include "../trait/issatisfd.hpp"

namespace x4 {
	template<typename T, auto fn = []<typename> {}>
	concept isfwdrange = std::ranges::forward_range<T> && x4::issatisfd<fn, std::ranges::range_value_t<T>>;
}
