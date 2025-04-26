#ifndef DETAIL_XIEITE_HEADER_FN_PIPE_OP
#	define DETAIL_XIEITE_HEADER_FN_PIPE_OP
#
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite::pipe_op {
	[[nodiscard]] constexpr auto operator|(auto&& arg, auto&& fn)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(arg)))
}

#endif
