export module xieite:math.roundHalfTowardZero;

import std;
import :concepts.Arithmetic;
import :math.divideHalfTowardZero;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfTowardZero(const Arithmetic value, const std::common_type_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideHalfTowardZero(value, step) * step;
	}
}
