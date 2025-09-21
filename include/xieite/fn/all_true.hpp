#ifndef DETAIL_XIEITE_HEADER_FN_ALL_TRUE
#	define DETAIL_XIEITE_HEADER_FN_ALL_TRUE
#
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	[[nodiscard]] constexpr bool all_true(auto&& fn, auto&&... args) XIEITE_ARROW_RET(
		(... && std::invoke_r<bool>(fn, XIEITE_FWD(args)))
	)
}

#endif
