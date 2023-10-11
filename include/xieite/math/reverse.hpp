#ifndef XIEITE_HEADER_MATH_REVERSE
#	define XIEITE_HEADER_MATH_REVERSE

#	include <concepts>
#	include <cstddef>
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer reverse(Integer value, const std::size_t base = 10) noexcept {
		const bool positive = value >= 0;
		value *= xieite::math::splitBoolean(positive);
		Integer result = 0;
		while (value) {
			result = result * base + value % base;
			value /= base;
		}
		return result * xieite::math::splitBoolean(positive);
	}
}

#endif
