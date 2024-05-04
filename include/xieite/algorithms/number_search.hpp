#ifndef XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH
#	define XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH

#	include <functional>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../math/absolute.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::Arithmetic Arithmetic_, xieite::concepts::Functable<bool(Arithmetic_)> Functor_>
	[[nodiscard]] constexpr Arithmetic_ numberSearch(Functor_&& selector, Arithmetic_ minimum, Arithmetic_ maximum)
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, Arithmetic_>) {
		while (true) {
			const Arithmetic_ middle = (minimum + maximum) / 2;
			if (xieite::math::almostEqual(middle, minimum) || xieite::math::almostEqual(middle, maximum)) {
				return middle;
			}
			(std::invoke(selector, middle) ? maximum : minimum) = middle;
		}
	}

	template<xieite::concepts::Arithmetic Arithmetic_, xieite::concepts::Functable<bool(Arithmetic_)> Functor_>
	[[nodiscard]] constexpr Arithmetic_ numberSearch(Functor_&& selector)
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, Arithmetic_>) {
		Arithmetic_ minimum = -1;
		Arithmetic_ maximum = 1;
		if (std::invoke(selector, 0)) {
			while (std::invoke(selector), minimum) {
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

#endif
