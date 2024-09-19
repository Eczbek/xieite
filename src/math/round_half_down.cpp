export module xieite:math.roundHalfDown;

import std;
import :concepts.Arithmetic;
import :math.divideHalfDown;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic roundHalfDown(const Arithmetic value, const std::type_identity_t<Arithmetic> step = 1) noexcept {
		return xieite::math::divideHalfDown(value, step) * step;
	}
}
