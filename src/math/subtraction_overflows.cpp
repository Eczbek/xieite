export module xieite:math.subtractionOverflows;

import std;
import :concepts.Arithmetic;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool subtractionOverflows(const Arithmetic minuend, const Arithmetic subtrahend) noexcept {
		return minuend && subtrahend && ((subtrahend >= 0) ? ((std::numeric_limits<Arithmetic>::min() + subtrahend) > minuend) : ((std::numeric_limits<Arithmetic>::max() + subtrahend) < minuend));
	}
}
