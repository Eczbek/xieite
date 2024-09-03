export module xieite:math.roundHalfDown;

import :concepts.Arithmetic;
import :math.divideHalfDown;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfDown(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideHalfDown(value, step) * step;
	}
}
