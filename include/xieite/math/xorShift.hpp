#ifndef XIEITE_HEADER__MATH__XOR_SHIFT
#	define XIEITE_HEADER__MATH__XOR_SHIFT

#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr Integral xorShift(const Integral value, const std::size_t bits) noexcept {
		return (value ^ (value >> bits));
	}
}

#endif
