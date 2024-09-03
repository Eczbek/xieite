export module xieite:math.roundHalfTowardZero;

import :concepts.Arithmetic;
import :math.divideHalfTowardZero;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfTowardZero(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideHalfTowardZero(value, step) * step;
	}
}
