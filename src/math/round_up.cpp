export module xieite:math.roundUp;

import std;
import :concepts.Arithmetic;
import :math.divideUp;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundUp(const Arithmetic value, const std::type_identity_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideUp(value, step) * step;
	}
}
