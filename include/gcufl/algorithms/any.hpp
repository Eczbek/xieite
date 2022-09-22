#pragma once

#include <concepts>


namespace gcufl::algorithms {
	template<typename... T> requires(requires(const T&... values) {
		{ (values || ...) } -> std::convertible_to<bool>;
	}) constexpr bool any(const T&... values) noexcept {
		return (values || ...);
	}

	template<typename... T>
	constexpr bool any(const T&...) noexcept {
		return false;
	}
}
