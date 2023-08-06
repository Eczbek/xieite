#ifndef XIEITE_HEADER__MATH__REVERSE
#	define XIEITE_HEADER__MATH__REVERSE

#	include <concepts>
#	include <cstddef>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]]
	constexpr Integer reverse(Integer value, const std::size_t base = 10) noexcept {
		const bool positive = value >= 0;
		value *= (positive * 2 - 1);
		Integer result = 0;
		while (value) {
			result = result * base + value % base;
			value /= base;
		}
		return (result * (positive * 2 - 1));
	}
}

#endif
