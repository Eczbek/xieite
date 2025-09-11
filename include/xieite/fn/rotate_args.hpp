#ifndef DETAIL_XIEITE_HEADER_FN_ROTATE_ARGS
#	define DETAIL_XIEITE_HEADER_FN_ROTATE_ARGS
#
#	include <cstddef>
#	include <functional>
#	include "../fn/unroll.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../pp/lift.hpp"

namespace xieite {
	template<std::size_t distance>
	[[nodiscard]] constexpr auto rotate_args(auto&& fn, auto&&... args)
		XIEITE_ARROW(xieite::unroll<sizeof...(args)>(
			[]<std::size_t... i>(auto&& fn, auto&&... args)
				XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args...[(i + distance % sizeof...(args)) % sizeof...(args)])...)),
			XIEITE_FWD(fn),
			XIEITE_FWD(args)...
		))

	template<std::size_t distance, typename T>
	[[nodiscard]] constexpr T rotate_args(auto&&... args)
		XIEITE_ARROW_RET(xieite::rotate_args<distance>(XIEITE_LIFT(T), XIEITE_FWD(args)...))
}

#endif
