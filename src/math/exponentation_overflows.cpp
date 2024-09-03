export module xieite:math.exponentationOverflows;

import std;
import :concepts.Arithmetic;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool exponentationOverflows(const Arithmetic base, const Arithmetic exponent) noexcept {
		const auto power = std::pow(base, exponent);
		if constexpr (!std::unsigned_integral<Arithmetic>) {
			if (power < std::numeric_limits<Arithmetic>::min()) {
				return true;
			}
		}
		return power > std::numeric_limits<Arithmetic>::max();
	}
}
