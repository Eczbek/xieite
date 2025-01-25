#pragma once

#include "../trait/collapse.hpp"

namespace xieite {
	template<typename T, typename U>
	[[nodiscard]] constexpr auto&& collapse_fwd(U&& x) noexcept {
		return static_cast<xieite::collapse<T, U>>(x);
	}
}
