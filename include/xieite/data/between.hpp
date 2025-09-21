#ifndef DETAIL_XIEITE_HEADER_DATA_BETWEEN
#	define DETAIL_XIEITE_HEADER_DATA_BETWEEN
#
#	include <functional>
#	include <ranges>
#	include "../data/after.hpp"
#	include "../data/before_last.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto between(auto&& range, auto&& after, auto&& before, auto&& after_pred = std::ranges::equal_to(), auto&& before_pred = decltype(after_pred)()) XIEITE_ARROW(
		xieite::before_last(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after), XIEITE_FWD(after_pred)), XIEITE_FWD(before), XIEITE_FWD(before_pred))
	)

	template<typename Range>
	[[nodiscard]] constexpr auto between(Range&& range, auto&& after, std::ranges::range_common_reference_t<Range> before, auto&& after_pred = std::ranges::equal_to()) XIEITE_ARROW(
		xieite::before_last(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after), XIEITE_FWD(after_pred)), XIEITE_FWD(before))
	)

	template<typename Range>
	[[nodiscard]] constexpr auto between(Range&& range, std::ranges::range_common_reference_t<Range> after, auto&& before, auto&& before_pred = std::ranges::equal_to()) XIEITE_ARROW(
		xieite::before_last(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after)), XIEITE_FWD(before), XIEITE_FWD(before_pred))
	)

	template<typename Range>
	[[nodiscard]] constexpr auto between(Range&& range, std::ranges::range_common_reference_t<Range> after, std::ranges::range_common_reference_t<Range> before) XIEITE_ARROW(
		xieite::before_last(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after)), XIEITE_FWD(before))
	)
}

#endif
