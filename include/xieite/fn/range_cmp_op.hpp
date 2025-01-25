#pragma once

#include <algorithm>
#include <ranges>

namespace xieite::range_cmp_op {
	template<std::ranges::input_range R1, std::ranges::input_range R2>
	[[nodiscard]] constexpr auto operator<=>(R1&& l, R2&& r) noexcept {
		return std::lexicographical_compare_three_way(l.begin(), l.end(), r.begin(), r.end());
	}
}
