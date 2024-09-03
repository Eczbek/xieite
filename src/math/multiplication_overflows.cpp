export module xieite:math.multiplicationOverflows;

import std;
import :concepts.Arithmetic;
import :math.absolute;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool multiplicationOverflows(const Arithmetic multiplier, const Arithmetic multiplicand) noexcept {
		return multiplier && multiplicand && ((xieite::math::absolute(((multiplier < 0) != (multiplicand < 0)) ? std::numeric_limits<Arithmetic>::min() : std::numeric_limits<Arithmetic>::max()) / xieite::math::absolute(multiplier)) < xieite::math::absolute(multiplicand));
	}
}
