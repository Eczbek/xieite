export module xieite:math.roundUp;

import :concepts.Arithmetic;
import :math.divideUp;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundUp(const Arithmetic value, const Arithmetic step = 1) noexcept {
		return xieite::math::divideUp(value, step) * step;
	}
}
