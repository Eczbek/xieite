#pragma once

#include <ranges>
#include <type_traits>
#include "../trait/isarith.hpp"

namespace x4 {
	template<std::ranges::forward_range R, typename T = std::common_type_t<std::ranges::range_value_t<R>, double>>
	requires(std::ranges::sized_range<R> && x4::isarith<std::ranges::range_value_t<R>>)
	[[nodiscard]] constexpr T mean(R&& range) noexcept {
		T result = 0;
		for (auto&& n : range) {
			result += static_cast<T>(n);
		}
		return result / std::ranges::size(range);
	}
}
