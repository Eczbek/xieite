export module xieite:math.additionOverflows;

import std;
import :concepts.Arithmetic;
import :math.isNegative;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool additionOverflows(const Arithmetic augend, const Arithmetic addend) noexcept {
		return augend && addend && (xieite::math::isNegative(augend) ? ((std::numeric_limits<Arithmetic>::min() - augend) > addend) : ((std::numeric_limits<Arithmetic>::max() - augend) < addend));
	}
}
