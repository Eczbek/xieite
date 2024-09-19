export module xieite:math.divideHalfDown;

import std;
import :concepts.Arithmetic;
import :math.sign;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic divideHalfDown(const Arithmetic dividend, const std::type_identity_t<Arithmetic> divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			const Arithmetic result = dividend / divisor;
			const Arithmetic fractional = std::fmod(result, 1);
			return std::floor(result) + (result < 0) + (fractional > 0.5) - (fractional <= -0.5);
		} else {
			const int quotientSign = xieite::math::sign(dividend, divisor);
			return static_cast<Arithmetic>(dividend / divisor + ((dividend % divisor * xieite::math::sign(dividend)) >= (divisor / 2 * xieite::math::sign(divisor) + ((divisor % 2) || (quotientSign >= 0)))) * quotientSign);
		}
	}
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for original integer division code
