#pragma once

namespace x4 {
	template<typename T>
	[[nodiscard]] constexpr T& tmp(T&& x = {}) noexcept {
		return { x };
	}
}
