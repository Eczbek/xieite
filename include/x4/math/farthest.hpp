#pragma once

#include <concepts>
#include "../math/diff.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T, std::convertible_to<T>... Us>
	[[nodiscard]] constexpr T farthest(T target, T first, Us... rest) noexcept {
		T result = first;
		(..., (result = (x4::diff(target, rest) > x4::diff(target, result)) ? rest : result));
		return result;
	}
}
