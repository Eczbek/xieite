#ifndef XIEITE_HEADER_MATH_ISPRIME
#	define XIEITE_HEADER_MATH_ISPRIME

#	include <concepts>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr bool isPrime(const Integral value) noexcept {
		for (Integral i = 0; (i * i) <= value; ++i) {
			if (!(value % i)) {
				return false;
			}
		}
		return value > 0;
	}
}

#endif
