#ifndef DETAIL_XIEITE_HEADER_FN_Y_COMBINATOR
#	define DETAIL_XIEITE_HEADER_FN_Y_COMBINATOR
#
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto y_combinator(auto&& fn)
		XIEITE_ARROW([fn = XIEITE_FWD(fn)](auto&&... args) XIEITE_ARROW(std::invoke(fn, fn, XIEITE_FWD(args)...)))
}

#endif
