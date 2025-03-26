#ifndef DETAIL_XIEITE_HEADER_FN_PIPE_OP
#	define DETAIL_XIEITE_HEADER_FN_PIPE_OP
#
#	include <concepts>
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite::pipe_op {
	template<typename T, std::invocable<T> F>
	[[nodiscard]] constexpr auto operator|(T&& arg, F&& fn)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(arg)))
}

#endif
