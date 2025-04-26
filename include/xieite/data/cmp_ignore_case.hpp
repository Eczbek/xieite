#ifndef DETAIL_XIEITE_HEADER_DATA_CMP_IGNORE_CASE
#	define DETAIL_XIEITE_HEADER_DATA_CMP_IGNORE_CASE
#
#	include <compare>
#	include <ranges>
#	include "../data/toupper.hpp"
#	include "../trait/is_char.hpp"
#	include "../trait/is_fwd_input_range.hpp"

namespace xieite {
	template<typename Range0, typename Range1>
	requires(xieite::is_fwd_input_range<Range0, []<xieite::is_char> {}> && xieite::is_fwd_input_range<Range1, []<xieite::is_char> {}>)
	[[nodiscard]] constexpr std::strong_ordering cmp_ignore_case(Range0&& lhs, Range1&& rhs) noexcept {
		auto iter0 = std::ranges::begin(lhs);
		auto iter1 = std::ranges::begin(rhs);
		while (true) {
			if (iter0 == lhs.end()) {
				return std::strong_ordering::less;
			}
			if (iter1 == rhs.end()) {
				return std::strong_ordering::greater;
			}
			if (std::strong_ordering order = xieite::toupper(*iter0) <=> xieite::toupper(*iter1); !std::is_eq(order)) {
				return order;
			}
			++iter0;
			++iter1;
		}
		return std::strong_ordering::equal;
	}
}

#endif
