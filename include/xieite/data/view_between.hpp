#ifndef DETAIL_XIEITE_HEADER_DATA_VIEW_BETWEEN
#	define DETAIL_XIEITE_HEADER_DATA_VIEW_BETWEEN
#
#	include "../data/view_after.hpp"
#	include "../data/view_before.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto view_between(auto&& range, auto&& a, auto&& b)
		XIEITE_ARROW(xieite::view_after(xieite::view_before(XIEITE_FWD(range), XIEITE_FWD(b)), XIEITE_FWD(a)))
}

#endif
