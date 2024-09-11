export module xieite:math.subtractionOverflows;

import std;
import :concepts.Arithmetic;
import :math.isNegative;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr bool subtractionOverflows(First first, const Rest... rest) noexcept {
		return first && (... || ([&first, rest] {
			if (rest && (xieite::math::isNegative(rest) ? ((std::numeric_limits<First>::max() + rest) < first) : ((std::numeric_limits<First>::min() + rest) > first))) {
				return true;
			}
			first -= static_cast<First>(rest);
			return false;
		})());
	}
}
