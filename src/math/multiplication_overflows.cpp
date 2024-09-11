export module xieite:math.multiplicationOverflows;

import std;
import :concepts.Arithmetic;
import :math.absolute;
import :math.isNegative;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr bool multiplicationOverflows(First first, const Rest... rest) noexcept {
		return first && (... || ([&first, rest] {
			if (rest && ((xieite::math::absolute((xieite::math::isNegative(first) != xieite::math::isNegative(rest)) ? std::numeric_limits<First>::min() : std::numeric_limits<First>::max()) / xieite::math::absolute(first)) < xieite::math::absolute(rest))) {
				return true;
			}
			first *= static_cast<First>(rest);
			return false;
		})());
	}
}
