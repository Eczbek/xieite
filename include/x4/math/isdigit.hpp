#pragma once

#include "../trait/isch.hpp"

namespace x4 {
	template<x4::isch Ch = char>
	[[nodiscard]] constexpr bool isdigit(Ch c) noexcept {
		return (c >= '0') && (c <= '9');
	}
}
