export module xieite:algorithms.numberSearch;

import std;
import :concepts.Arithmetic;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;
import :math.almostEqual;
import :math.isNegative;

export namespace xieite::algorithms {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Invocable<bool(Arithmetic)> Functor>
	[[nodiscard]] constexpr Arithmetic numberSearch(Functor&& selector, Arithmetic minimum, Arithmetic maximum)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(Arithmetic)>) {
		while (true) {
			const Arithmetic middle = static_cast<Arithmetic>((minimum + maximum) / 2);
			if (xieite::math::almostEqual(middle, minimum) || xieite::math::almostEqual(middle, maximum)) {
				return middle;
			}
			(std::invoke_r<bool>(selector, middle) ? maximum : minimum) = middle;
		}
	}

	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Invocable<bool(Arithmetic)> Functor>
	[[nodiscard]] constexpr Arithmetic numberSearch(Functor&& selector)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(Arithmetic)>) {
		if constexpr (!std::unsigned_integral<Arithmetic>) {
			if (std::invoke_r<bool>(selector, static_cast<Arithmetic>(0))) {
				Arithmetic minimum = -1;
				while (std::invoke_r<bool>(selector, minimum)) {
					minimum *= 2;
				}
				return xieite::algorithms::numberSearch<Arithmetic>(selector, minimum, 0);
			}
		}
		Arithmetic maximum = 1;
		while (!std::invoke_r<bool>(selector, maximum)) {
			maximum *= 2;
		}
		return xieite::algorithms::numberSearch<Arithmetic>(selector, 0, maximum);
	}
}
