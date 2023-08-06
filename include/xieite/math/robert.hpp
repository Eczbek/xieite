#ifndef XIEITE_HEADER__MATH__ROBERT
#	define XIEITE_HEADER__MATH__ROBERT

#	include <concepts>
#	include <limits>
#	include <numbers>

namespace xieite::math {
	template<std::integral Integer, std::floating_point Floating = double>
	inline constexpr Integer robert = std::numeric_limits<Integer>::max() / std::numbers::phi_v<Floating>;
}

// Thanks to melak47 for naming this constant

#endif
