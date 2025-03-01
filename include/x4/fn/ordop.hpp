#pragma once

#include <compare>
#include "../trait/isord.hpp"

namespace x4::ordop {
	template<x4::isord Ord>
	[[nodiscard]] constexpr Ord operator&(Ord l, Ord r) noexcept {
		return !std::is_eq(l) && !std::is_eq(r);
	}

	template<x4::isord Ord>
	[[nodiscard]] constexpr Ord operator|(Ord l, Ord r) noexcept {
		return std::is_eq(l) ? r : l;
	}
}
