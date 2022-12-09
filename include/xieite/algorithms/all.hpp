#pragma once
#include <concepts> // std::convertible_to

namespace xieite::algorithms {
	template<typename... T>
	requires(requires(T... values) {
		{ (values && ...) } -> std::convertible_to<bool>;
	})
	[[nodiscard]]
	constexpr bool all(const T&... values) noexcept {
		return (values && ...);
	}

	template<typename... T>
	[[nodiscard]]
	constexpr bool all(const T&...) noexcept {
		return false;
	}
}
