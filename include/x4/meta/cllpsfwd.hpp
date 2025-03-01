#pragma once

#include "../trait/cllpsref.hpp"

namespace x4 {
	template<typename T, typename U>
	[[nodiscard]] constexpr auto&& cllpsfwd(U&& x) noexcept {
		return static_cast<x4::cllpsref<T, U>>(x);
	}
}
