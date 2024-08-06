#ifndef XIEITE_HEADER_MATH_SIGN
#	define XIEITE_HEADER_MATH_SIGN

#	include <concepts>
#	include "../concepts/arithmetic.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic First_, std::same_as<First_>... Rest_>
	[[nodiscard]] constexpr int sign(const First_ first, const Rest_... rest) noexcept {
		static constexpr auto get = [](const First_ value) {
			return (value > 0) - xieite::math::isNegative(value);
		};
		return (get(first) * ... * get(rest));
	}
}

#endif
