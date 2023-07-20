#ifndef XIEITE_HEADER_MATH_REVERSE
#	define XIEITE_HEADER_MATH_REVERSE

#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]]
	constexpr Integral reverse(Integral value, const std::size_t base = 10) noexcept {
		const bool positive = value >= 0;
		value *= (positive * 2 - 1);
		Integral result = 0;
		while (value) {
			result = result * base + value % base;
			value /= base;
		}
		return result * (positive * 2 - 1);
	}
}

#endif
