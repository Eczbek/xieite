#ifndef DETAIL_XIEITE_HEADER_FN_MIN_ARGS
#	define DETAIL_XIEITE_HEADER_FN_MIN_ARGS
#
#	include <cstddef>
#	include <functional>
#	include <tuple>
#	include "../fn/unroll.hpp"
#	include "../meta/subtuple.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../pp/lift.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto min_args(auto&& fn, auto&&... args) XIEITE_ARROW(
		XIEITE_LIFT(std::apply)(
			XIEITE_FWD(fn),
			xieite::subtuple<0, xieite::unroll<sizeof...(args)>([]<std::size_t... count> -> std::size_t {
				std::size_t min = 0;
				(void)(... || (xieite::unroll<count>([]<std::size_t... i> -> bool {
					return requires { std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args...[i])...); };
				}) || !++min));
				return min;
			})>(std::make_tuple(XIEITE_FWD(args)...))
		)
	)
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=121325
// https://github.com/llvm/llvm-project/issues/151432
