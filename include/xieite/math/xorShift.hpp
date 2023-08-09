#ifndef XIEITE_HEADER__MATH__XOR_SHIFT
#	define XIEITE_HEADER__MATH__XOR_SHIFT

#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::integral Integer>
	constexpr Integer xorShift(const Integer value, const std::size_t bits) noexcept {
		return (value ^ (value >> bits));
	}
}

#endif
