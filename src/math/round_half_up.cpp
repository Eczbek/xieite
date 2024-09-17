export module xieite:math.roundHalfUp;

import std;
import :concepts.Arithmetic;
import :math.divideHalfUp;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfUp(const Arithmetic value, const std::common_type_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideHalfUp(value, step) * step;
	}
}
