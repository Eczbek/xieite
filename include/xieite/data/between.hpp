#ifndef DETAIL_XIEITE_HEADER_DATA_BETWEEN
#	define DETAIL_XIEITE_HEADER_DATA_BETWEEN
#
#	include "../data/after.hpp"
#	include "../data/before.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto between(auto&& range, auto&& a, auto&& b)
		XIEITE_ARROW(xieite::after(xieite::before(XIEITE_FWD(range), XIEITE_FWD(b)), XIEITE_FWD(a)))
}

#endif
