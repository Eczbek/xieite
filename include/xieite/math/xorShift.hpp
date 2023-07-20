#ifndef XIEITE_HEADER_MATH_XORSHIFT
#	define XIEITE_HEADER_MATH_XORSHIFT

#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr Integral xorShift(const Integral value, const std::size_t bits) noexcept {
		return value ^ (value >> bits);
	}
}

#endif
