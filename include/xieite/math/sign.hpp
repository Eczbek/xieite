#pragma once

#include "../math/neg.hpp"
#include "../math/split_bool.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T, xieite::is_arith... Ts>
	[[nodiscard]] constexpr int sign(T first, Ts... rest) noexcept {
		return (xieite::split_bool(!xieite::neg(first)) * ... * xieite::split_bool(!xieite::neg(rest)));
	}
}
