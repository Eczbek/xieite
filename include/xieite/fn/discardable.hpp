#ifndef DETAIL_XIEITE_HEADER_FN_DISCARDABLE
#	define DETAIL_XIEITE_HEADER_FN_DISCARDABLE
#
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	constexpr auto discardable(auto&& fn, auto&&... args)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...))
}

#endif
