#ifndef DETAIL_XIEITE_HEADER_FN_APPLY_AS_TUPLE
#	define DETAIL_XIEITE_HEADER_FN_APPLY_AS_TUPLE
#
#	include <tuple>
#	include "../meta/make_tuple.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../pp/lift.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto apply_as_tuple(auto&& fn, auto&& x)
		XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::make_tuple(XIEITE_FWD(x))))

	template<typename T>
	[[nodiscard]] constexpr T apply_as_tuple(auto&& x)
		XIEITE_ARROW_RET(xieite::apply_as_tuple(XIEITE_LIFT(T), XIEITE_FWD(x)))
}

#endif
