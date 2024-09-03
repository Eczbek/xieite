export module xieite:math.roundTowardInfinity;

import :concepts.Arithmetic;
import :math.divideTowardInfinity;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundTowardInfinity(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideTowardInfinity(value, step) * step;
	}
}
