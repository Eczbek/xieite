#ifndef XIEITE_HEADER__ALGORITHMS__NUMBER_SEARCH
#	define XIEITE_HEADER__ALGORITHMS__NUMBER_SEARCH

#	include "../concepts/Arithmetic.hpp"
#	include "../concepts/Functable.hpp"
#	include "../math/absolute.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functable<bool(Arithmetic)> Functable>
	[[nodiscard]]
	constexpr Arithmetic numberSearch(const Functable& selector, Arithmetic minimum, Arithmetic maximum) {
		while (true) {
			const Arithmetic middle = (minimum + maximum) / 2;
			if (xieite::math::almostEqual(middle, minimum) || xieite::math::almostEqual(middle, maximum)) {
				return middle;
			}
			(selector(middle) ? maximum : minimum) = middle;
		}
	}

	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functable<bool(Arithmetic)> Functable>
	[[nodiscard]]
	constexpr Arithmetic numberSearch(const Functable& selector) {
		Arithmetic minimum = -1;
		Arithmetic maximum = 1;
		if (selector(0)) {
			while (selector(minimum)) {
				minimum -= xieite::math::absolute(minimum);
			}
			return xieite::algorithms::numberSearch(selector, minimum, 0);
		}
		while (!selector(maximum)) {
			maximum += xieite::math::absolute(maximum);
		}
		return xieite::algorithms::numberSearch(selector, 0, maximum);
	}
}

#endif
