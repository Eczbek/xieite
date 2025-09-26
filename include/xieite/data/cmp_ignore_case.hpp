#ifndef DETAIL_XIEITE_HEADER_DATA_CMP_IGNORE_CASE
#	define DETAIL_XIEITE_HEADER_DATA_CMP_IGNORE_CASE
#
#	include <compare>
#	include <ranges>
#	include "../data/toupper.hpp"
#	include "../trait/is_char.hpp"
#	include "../trait/is_fwd_range.hpp"

namespace xieite {
	[[nodiscard]] constexpr std::strong_ordering cmp_ignore_case(
		xieite::is_fwd_range<[]<xieite::is_char> {}> auto&& lhs_range,
		xieite::is_fwd_range<[]<xieite::is_char> {}> auto&& rhs_range
	) noexcept {
		auto lhs = std::ranges::begin(lhs_range);
		auto rhs = std::ranges::begin(rhs_range);
		// FIXME: Make these references?
		const auto lhs_end = std::ranges::end(lhs_range);
		const auto rhs_end = std::ranges::end(rhs_range);
		while (true) {
			if ((lhs == lhs_end) || (rhs == rhs_end)) {
				return (lhs == lhs_end) <=> (rhs == rhs_end);
			}
			// FIXME: Make this auto? Then it could be one line.
			if (const std::strong_ordering order
					= xieite::toupper(*lhs) <=> xieite::toupper(*rhs);
				!std::is_eq(order)
			) {
				return order;
			}
			++lhs;
			++rhs;
		}
	}
}

#endif
