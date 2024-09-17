export module xieite:math.roundDown;

import std;
import :concepts.Arithmetic;
import :math.divideDown;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundDown(const Arithmetic value, const std::common_type_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideDown(value, step) * step;
	}
}
