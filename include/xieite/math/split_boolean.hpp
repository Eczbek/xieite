#ifndef XIEITE_HEADER_MATH_SPLIT_BOOLEAN
#	define XIEITE_HEADER_MATH_SPLIT_BOOLEAN

namespace xieite::math {
	[[nodiscard]] constexpr int splitBoolean(const bool value) noexcept {
		return value * 2 - 1;
	}
}

#endif
