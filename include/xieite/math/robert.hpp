#ifndef XIEITE_HEADER_MATH_ROBERT
#	define XIEITE_HEADER_MATH_ROBERT

#	include <concepts>
#	include <limits>
#	include <numbers>

namespace xieite::math {
	template<std::integral Integral>
	inline constexpr Integral robert = std::numeric_limits<Integral>::max() / std::numbers::phi_v<double>;
}

// Thanks to melak47 for naming this constant

#endif
