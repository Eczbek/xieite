#ifndef DETAIL_XIEITE_HEADER_DATA_CMP_IGNORE_CASE
#	define DETAIL_XIEITE_HEADER_DATA_CMP_IGNORE_CASE
#
#	include <compare>
#	include <ranges>
#	include "../data/toupper.hpp"
#	include "../trait/is_char.hpp"
#	include "../trait/is_fwd_range.hpp"

namespace xieite {
	[[nodiscard]] constexpr std::strong_ordering cmp_ignore_case(xieite::is_fwd_range<[]<xieite::is_char> {}> auto&& lhs, xieite::is_fwd_range<[]<xieite::is_char> {}> auto&& rhs) noexcept {
		auto iter0 = std::ranges::begin(lhs);
		auto iter1 = std::ranges::begin(rhs);
		const auto end0 = std::ranges::end(lhs);
		const auto end1 = std::ranges::end(rhs);
		while (true) {
			if ((iter0 == end0) || (iter1 == end1)) {
				return (iter0 == end0) <=> (iter1 == end1);
			}
			if (const std::strong_ordering order = xieite::toupper(*iter0) <=> xieite::toupper(*iter1); !std::is_eq(order)) {
				return order;
			}
			++iter0;
			++iter1;
		}
	}
}

#endif
