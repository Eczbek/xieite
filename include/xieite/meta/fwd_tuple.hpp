#pragma once

#include <tuple>
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"
#include "../trait/is_spec.hpp"

namespace xieite {
	template<xieite::is_spec<std::tuple> Tuple>
	[[nodiscard]] constexpr auto fwd_tuple(Tuple&& tuple) noexcept {
		return std::apply(XIEITE_LIFT(std::forward_as_tuple), XIEITE_FWD(tuple));
	}
}
