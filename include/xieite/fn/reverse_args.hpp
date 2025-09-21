#ifndef DETAIL_XIEITE_HEADER_FN_REVERSE_ARGS
#	define DETAIL_XIEITE_HEADER_FN_REVERSE_ARGS
#
#	include <tuple>
#	include "../meta/reverse_tuple.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../pp/lift.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto reverse_args(auto&& fn, auto&&... args) XIEITE_ARROW(
		std::apply(XIEITE_FWD(fn), xieite::reverse_tuple(std::forward_as_tuple(XIEITE_FWD(args)...)))
	)

	template<typename T>
	[[nodiscard]] constexpr T reverse_args(auto&&... args) XIEITE_ARROW_RET(
		xieite::reverse_args(XIEITE_LIFT(T), XIEITE_FWD(args)...)
	)
}

#endif
