#ifndef XIEITE_HEADER_MATH_MINIMALBITS
#	define XIEITE_HEADER_MATH_MINIMALBITS

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr std::size_t minimalBits(const Integral value) noexcept {
		return std::ceil(std::log2(static_cast<std::make_unsigned_t<Integral>>(value) + 1 + !value));
	}
}

#endif
