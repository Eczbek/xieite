#ifndef DETAIL_XIEITE_HEADER_FN_RANGE_CMP
#	define DETAIL_XIEITE_HEADER_FN_RANGE_CMP
#
#	include <algorithm>
#	include <ranges>
#	include "../fn/synth_three_way.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::ranges::input_range R0, std::ranges::input_range R1>
	[[nodiscard]] constexpr auto range_cmp(R0&& lhs, R1&& rhs)
	noexcept(xieite::is_noex_range<R0> && xieite::is_noex_range<R1> && noexcept(xieite::synth_three_way(*lhs.begin(), *rhs.begin()))) {
		return std::lexicographical_compare_three_way(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), xieite::synth_three_way);
	}
}

#endif
