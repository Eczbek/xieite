#pragma once

#include <algorithm>
#include <ranges>
#include "../fn/synth_three_way.hpp"
#include "../trait/is_noex_range.hpp"

namespace xieite::range_cmp_op {
	template<std::ranges::input_range R0, std::ranges::input_range R1>
	[[nodiscard]] constexpr auto operator<=>(R0&& l, R1&& r)
	noexcept(xieite::is_noex_range<R0> && xieite::is_noex_range<R1> && noexcept(xieite::synth_three_way(*l.begin(), *r.begin()))) {
		return std::lexicographical_compare_three_way(l.begin(), l.end(), r.begin(), r.end(), xieite::synth_three_way);
	}
}
