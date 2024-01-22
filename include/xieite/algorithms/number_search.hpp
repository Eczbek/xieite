#ifndef XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH
#	define XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH

#	include <functional>
#	include <utility>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../math/absolute.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::Arithmetic Number, xieite::concepts::Functable<bool(Number)> Functor>
	[[nodiscard]] constexpr Number numberSearch(Functor&& selector, Number minimum, Number maximum)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Number>) {
		while (true) {
			const Number middle = (minimum + maximum) / 2;
			if (xieite::math::almostEqual(middle, minimum) || xieite::math::almostEqual(middle, maximum)) {
				return middle;
			}
			(std::invoke(std::forward<Functor>(selector), middle) ? maximum : minimum) = middle;
		}
	}

	template<xieite::concepts::Arithmetic Number, xieite::concepts::Functable<bool(Number)> Functor>
	[[nodiscard]] constexpr Number numberSearch(Functor&& selector)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Number>) {
		Number minimum = -1;
		Number maximum = 1;
		if (std::invoke(std::forward<Functor>(selector), 0)) {
			while (std::invoke(std::forward<Functor>(selector), minimum)) {
				minimum -= xieite::math::absolute(minimum);
			}
			return xieite::algorithms::numberSearch(std::forward<Functor>(selector), minimum, 0);
		}
		while (!std::invoke(std::forward<Functor>(selector), maximum)) {
			maximum += xieite::math::absolute(maximum);
		}
		return xieite::algorithms::numberSearch(std::forward<Functor>(selector), 0, maximum);
	}
}

#endif
