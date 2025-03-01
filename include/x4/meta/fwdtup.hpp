#pragma once

#include <tuple>
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"
#include "../trait/istuplike.hpp"

namespace x4 {
	template<x4::istuplike Tuple>
	[[nodiscard]] constexpr auto fwdtup(Tuple&& x) noexcept {
		return std::apply(X4LIFT(std::forward_as_tuple), X4FWD(x));
	}
}
