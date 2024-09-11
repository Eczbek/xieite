export module xieite:math.additionOverflows;

import std;
import :concepts.Arithmetic;
import :math.isNegative;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr bool additionOverflows(First first, const Rest... rest) noexcept {
		return first && (... || ([&first, rest] {
			if (rest && (xieite::math::isNegative(first) ? ((std::numeric_limits<First>::min() - first) > rest) : ((std::numeric_limits<First>::max() - first) < rest))) {
				return true;
			}
			first += static_cast<First>(rest);
			return false;
		})());
	}
}
