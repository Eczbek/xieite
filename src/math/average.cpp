export module xieite:math.average;

import std;
import :concepts.Arithmetic;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr First average(const First first, const Rest... rest) noexcept {
		static constexpr First size = static_cast<First>(sizeof...(rest) + 1);
		First result = first / size + (... + (rest / size));
		if constexpr (std::integral<First>) {
			result += (first % size + (... + (rest % size))) / size;
		}
		return result;
	}
}
