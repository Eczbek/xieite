#pragma once

#include <concepts>
#include <type_traits>
#include "../meta/trysign.hpp"
#include "../meta/tryunsign.hpp"

namespace x4 {
	template<std::integral T>
	constexpr auto sgncast = []<std::integral U>(U n) static noexcept {
		return static_cast<T>(static_cast<std::conditional_t<std::signed_integral<T>, x4::trysign<U>, x4::tryunsign<U>>>(n));
	};
}
