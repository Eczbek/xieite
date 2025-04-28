#ifndef DETAIL_XIEITE_HEADER_FN_PIPE_OP
#	define DETAIL_XIEITE_HEADER_FN_PIPE_OP
#
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite::pipe_op {
	[[nodiscard]] constexpr auto operator|(auto&& arg, auto&& fn)
		XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(arg)))

	[[nodiscard]] constexpr auto operator*(auto&& fn0, auto&& fn1) noexcept {
		return [&fn0, &fn1][[nodiscard]](auto&&... args) mutable
			XIEITE_ARROW(std::invoke(XIEITE_FWD(fn1), std::invoke(XIEITE_FWD(fn0), XIEITE_FWD(args)...)));
	}
}

#endif
