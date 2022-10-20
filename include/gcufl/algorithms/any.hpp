#pragma once
#include <concepts>

namespace gcufl::algorithms {
	template<typename... T>
	[[nodiscard]]
	requires(requires(T... values) {
		{ (values || ...) } -> std::convertible_to<bool>;
	}) constexpr bool any(const T&... values) noexcept {
		return (values || ...);
	}

	template<typename... T>
	[[nodiscard]]
	constexpr bool any(const T&...) noexcept {
		return false;
	}
}
