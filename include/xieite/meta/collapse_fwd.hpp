#pragma once

#include "../trait/collapse_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	[[nodiscard]] constexpr auto&& collapse_fwd(U&& x) noexcept {
		return static_cast<xieite::collapse_ref<T, U>>(x);
	}
}
