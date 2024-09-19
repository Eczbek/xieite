export module xieite:math.modulo;

import std;
import :concepts.Arithmetic;
import :math.remainder;
import :math.sign;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic modulo(const Arithmetic dividend, const std::type_identity_t<Arithmetic> divisor) noexcept {
		return xieite::math::remainder(xieite::math::remainder(dividend, divisor) + divisor * (xieite::math::sign(dividend) != xieite::math::sign(divisor)), divisor);
	}
}
