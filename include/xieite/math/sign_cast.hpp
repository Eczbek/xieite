#pragma once

#include <concepts>
#include <type_traits>
#include "../meta/try_sign.hpp"
#include "../meta/try_unsign.hpp"

namespace xieite {
	template<std::integral T, std::integral U>
	[[nodiscard]] constexpr T sign_cast(U n) noexcept {
		return static_cast<T>(static_cast<std::conditional_t<std::signed_integral<T>, xieite::try_sign<U>, xieite::try_unsign<U>>>(n));
	}
}
