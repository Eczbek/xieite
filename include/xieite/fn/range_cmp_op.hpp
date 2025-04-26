#ifndef DETAIL_XIEITE_HEADER_FN_RANGE_CMP_OP
#	define DETAIL_XIEITE_HEADER_FN_RANGE_CMP_OP
#
#	include <algorithm>
#	include <ranges>
#	include "../fn/synth_three_way.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite::range_cmp_op {
	template<std::ranges::input_range R0, std::ranges::input_range R1>
	[[nodiscard]] constexpr auto operator<=>(R0&& lhs, R1&& rhs)
	noexcept(xieite::is_noex_range<R0> && xieite::is_noex_range<R1> && noexcept(xieite::synth_three_way(*lhs.begin(), *rhs.begin()))) {
		return std::lexicographical_compare_three_way(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), xieite::synth_three_way);
	}
}

#endif
