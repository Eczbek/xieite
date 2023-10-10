#pragma once

#include <functional>
#include "../concepts/numeric.hpp"
#include "../concepts/functable.hpp"
#include "../math/absolute.hpp"
#include "../math/almost_equal.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::Numeric Number, xieite::concepts::Functable<bool(Number)> Functor>
	[[nodiscard]] constexpr Number numberSearch(const Functor& selector, Number minimum, Number maximum) {
		while (true) {
			const Number middle = (minimum + maximum) / 2;
			if (xieite::math::almostEqual(middle, minimum) || xieite::math::almostEqual(middle, maximum)) {
				return middle;
			}
			(std::invoke(selector, middle) ? maximum : minimum) = middle;
		}
	}

	template<xieite::concepts::Numeric Number, xieite::concepts::Functable<bool(Number)> Functor>
	[[nodiscard]] constexpr Number numberSearch(const Functor& selector) {
		Number minimum = -1;
		Number maximum = 1;
		if (std::invoke(selector, 0)) {
			while (std::invoke(selector, minimum)) {
				minimum -= xieite::math::absolute(minimum);
			}
			return xieite::algorithms::numberSearch(selector, minimum, 0);
		}
		while (!std::invoke(selector, maximum)) {
			maximum += xieite::math::absolute(maximum);
		}
		return xieite::algorithms::numberSearch(selector, 0, maximum);
	}
}
