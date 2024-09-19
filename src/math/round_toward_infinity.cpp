export module xieite:math.roundTowardInfinity;

import std;
import :concepts.Arithmetic;
import :math.divideTowardInfinity;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundTowardInfinity(const Arithmetic value, const std::type_identity_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideTowardInfinity(value, step) * step;
	}
}
