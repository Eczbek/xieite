export module xieite:math.roundHalfTowardInfinity;

import :concepts.Arithmetic;
import :math.divideHalfTowardInfinity;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfTowardInfinity(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideHalfTowardInfinity(value, step) * step;
	}
}
