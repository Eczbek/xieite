export module xieite:math.roundTowardZero;

import std;
import :concepts.Arithmetic;
import :math.divideTowardZero;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundTowardZero(const Arithmetic value, const std::type_identity_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideTowardZero(value, step) * step;
	}
}
