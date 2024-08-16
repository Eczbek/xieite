#ifndef XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH
#	define XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH

#	include <functional>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/functor.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../math/almost_equal.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functor<bool(Arithmetic)> Functor>
	[[nodiscard]] constexpr Arithmetic numberSearch(Functor&& selector, Arithmetic minimum, Arithmetic maximum)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Arithmetic>) {
		while (true) {
			const Arithmetic middle = (minimum + maximum) / 2;
			if (xieite::math::almostEqual(middle, minimum) || xieite::math::almostEqual(middle, maximum)) {
				return middle;
			}
			(std::invoke(selector, middle) ? maximum : minimum) = middle;
		}
	}

	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functor<bool(Arithmetic)> Functor>
	[[nodiscard]] constexpr Arithmetic numberSearch(Functor&& selector)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Arithmetic>) {
		if constexpr (!std::unsigned_integral<Arithmetic>) {
			if (std::invoke(selector, 0)) {
				Arithmetic minimum = -1;
				while (std::invoke(selector), minimum) {
					minimum *= 2;
				}
				return xieite::algorithms::numberSearch(selector, minimum, 0);
			}
		}
		Arithmetic maximum = 1;
		while (!std::invoke(selector, maximum)) {
			maximum *= 2;
		}
		return xieite::algorithms::numberSearch(selector, 0, maximum);
	}
}

#endif
