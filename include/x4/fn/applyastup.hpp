#pragma once

#include <tuple>
#include "../meta/mktup.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"

namespace x4 {
	template<typename F, typename V>
	[[nodiscard]] constexpr auto applyastup(F&& fn, V&& x)
		X4AR(std::apply(X4FWD(fn), x4::mktup(X4FWD(x))))

	template<typename T, typename V>
	[[nodiscard]] constexpr T applyastup(V&& x)
		X4ARRET(x4::applyastup(X4LIFT(T), X4FWD(x)))
}
