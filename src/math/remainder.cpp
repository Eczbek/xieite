export module xieite:math.remainder;

import std;
import :concepts.Arithmetic;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic remainder(const Arithmetic dividend, const std::common_type_t<Arithmetic> divisor) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			return std::fmod(dividend, divisor);
		} else {
			return dividend % divisor;
		}
	}
}
