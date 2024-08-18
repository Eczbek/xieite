#ifndef XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH
#	define XIEITE_HEADER_ALGORITHMS_NUMBER_SEARCH

#	include <functional>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/functor.hpp"
#	include "../math/almost_equal.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functor<bool(Arithmetic)> Functor>
	[[nodiscard]] constexpr Arithmetic numberSearch(Functor&& selector, Arithmetic minimum, Arithmetic maximum)
	noexcept(std::is_nothrow_invocable_v<Functor, Arithmetic>) {
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
	noexcept(std::is_nothrow_invocable_v<Functor, Arithmetic>) {
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
