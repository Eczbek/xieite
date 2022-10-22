#pragma once
#include <concepts>

namespace gcufl::algorithms {
	template<typename... T>
	requires(requires(T... values) {
		{ (values || ...) } -> std::convertible_to<bool>;
	})
	[[nodiscard]]
	constexpr bool any(const T&... values) noexcept {
		return (values || ...);
	}

	template<typename... T>
	[[nodiscard]]
	constexpr bool any(const T&...) noexcept {
		return false;
	}
}
