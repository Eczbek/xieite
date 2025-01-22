export module xieite:sign_cast;

import std;
import :try_sign;
import :try_unsign;

export namespace xieite {
	template<std::integral T, std::integral U>
	[[nodiscard]] constexpr T sign_cast(U n) noexcept {
		return static_cast<T>(static_cast<std::conditional_t<std::signed_integral<T>, xieite::try_sign<U>, xieite::try_unsign<U>>>(n));
	}
}
