#ifndef XIEITE_HEADER__MATH__IS_PRIME
#	define XIEITE_HEADER__MATH__IS_PRIME

#	include <concepts>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr bool isPrime(const Integral value) noexcept {
		if (value < 0) {
			return false;
		}
		for (Integral i = 0; (i * i) <= value; ++i) {
			if (!(value % i)) {
				return false;
			}
		}
		return true;
	}
}

#endif
