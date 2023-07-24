#ifndef XIEITE_HEADER_ALGORITHMS_NUMBERSEARCH
#	define XIEITE_HEADER_ALGORITHMS_NUMBERSEARCH

#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/concepts/Functable.hpp>
#	include <xieite/math/absolute.hpp>
#	include <xieite/math/almostEqual.hpp>

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
			maximum = 0;
			while (selector(minimum)) {
				minimum -= xieite::math::absolute(minimum);
			}
		} else {
			minimum = 0;
			while (!selector(maximum)) {
				maximum += xieite::math::absolute(maximum);
			}
		}
		return xieite::algorithms::numberSearch(selector, minimum, maximum);
	}
}

#endif
