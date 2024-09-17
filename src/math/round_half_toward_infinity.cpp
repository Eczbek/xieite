export module xieite:math.roundHalfTowardInfinity;

import std;
import :concepts.Arithmetic;
import :math.divideHalfTowardInfinity;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfTowardInfinity(const Arithmetic value, const std::common_type_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideHalfTowardInfinity(value, step) * step;
	}
}
