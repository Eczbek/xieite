#ifndef DETAIL_XIEITE_HEADER_DATA_BETWEEN
#	define DETAIL_XIEITE_HEADER_DATA_BETWEEN
#
#	include <functional>
#	include <ranges>
#	include "../data/after.hpp"
#	include "../data/before.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename Range, typename After, typename Before, typename AfterPred = std::ranges::equal_to, typename BeforePred = AfterPred>
	[[nodiscard]] constexpr auto between(Range&& range, After&& after, Before&& before, AfterPred&& after_pred = {}, BeforePred&& before_pred = {})
		XIEITE_ARROW(xieite::before(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after), XIEITE_FWD(after_pred)), XIEITE_FWD(before), XIEITE_FWD(before_pred)))

	template<typename Range, typename After, typename AfterPred = std::ranges::equal_to>
	[[nodiscard]] constexpr auto between(Range&& range, After&& after, std::ranges::range_common_reference_t<Range> before, AfterPred&& after_pred = {})
		XIEITE_ARROW(xieite::before(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after), XIEITE_FWD(after_pred)), XIEITE_FWD(before)))

	template<typename Range, typename Before, typename BeforePred = std::ranges::equal_to>
	[[nodiscard]] constexpr auto between(Range&& range, std::ranges::range_common_reference_t<Range> after, Before&& before, BeforePred&& before_pred = {})
		XIEITE_ARROW(xieite::before(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after)), XIEITE_FWD(before), XIEITE_FWD(before_pred)))

	template<typename Range>
	[[nodiscard]] constexpr auto between(Range&& range, std::ranges::range_common_reference_t<Range> after, std::ranges::range_common_reference_t<Range> before)
		XIEITE_ARROW(xieite::before(xieite::after(XIEITE_FWD(range), XIEITE_FWD(after)), XIEITE_FWD(before)))
}

#endif
