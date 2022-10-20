#pragma once
#include <concepts>

namespace gcufl::algorithms {
	template<typename... T>
	[[nodiscard]]
	requires(requires(T... values) {
		{ (values && ...) } -> std::convertible_to<bool>;
	}) constexpr bool all(const T&... values) noexcept {
		return (values && ...);
	}

	template<typename... T>
	[[nodiscard]]
	constexpr bool all(const T&...) noexcept {
		return false;
	}
}
