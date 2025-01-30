#pragma once

#include <tuple>
#include <type_traits>
#include "../ctnr/make_tuple.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"

namespace xieite {
	template<typename F, typename V>
	[[nodiscard]] constexpr auto apply_as_tuple(F&& fn, V&& x)
		XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::make_tuple(XIEITE_FWD(x))))

	template<typename T, typename V>
	[[nodiscard]] constexpr T apply_as_tuple(V&& x)
		XIEITE_ARROW_RET(xieite::apply_as_tuple(XIEITE_LIFT(T), XIEITE_FWD(x)))
}
