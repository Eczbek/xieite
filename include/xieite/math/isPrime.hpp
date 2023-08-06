#ifndef XIEITE_HEADER__MATH__IS_PRIME
#	define XIEITE_HEADER__MATH__IS_PRIME

#	include <concepts>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]]
	constexpr bool isPrime(const Integer value) noexcept {
		if (value < 0) {
			return false;
		}
		for (Integer i = 0; (i * i) <= value; ++i) {
			if (!(value % i)) {
				return false;
			}
		}
		return true;
	}
}

#endif
