export module xieite:sign_cast;

import std;
import :try_signed;
import :try_unsigned;

export namespace xieite {
	template<std::integral T, std::integral U>
	[[nodiscard]] constexpr T sign_cast(U value) noexcept {
		return static_cast<T>(static_cast<std::conditional_t<std::signed_integral<T>, xieite::try_signed<U>, xieite::try_unsigned<U>>>(value));
	}
}
