export module xieite:math.roundTowardInfinity;

import std;
import :concepts.Arithmetic;
import :math.divideTowardInfinity;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundTowardInfinity(const Arithmetic value, const std::common_type_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideTowardInfinity(value, step) * step;
	}
}
