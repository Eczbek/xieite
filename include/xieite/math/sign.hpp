#ifndef XIEITE_HEADER_MATH_SIGN
#	define XIEITE_HEADER_MATH_SIGN

#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::same_as<First>... Rest>
	[[nodiscard]] constexpr int sign(const First first, const Rest... rest) noexcept {
		static constexpr auto get = [](const First value) -> int {
			return (value > 0) - xieite::math::isNegative(value);
		};
		return (get(first) * ... * get(rest));
	}
}

#endif
