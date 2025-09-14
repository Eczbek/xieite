#ifndef DETAIL_XIEITE_HEADER_MATH_EXP_SEARCH
#	define DETAIL_XIEITE_HEADER_MATH_EXP_SEARCH
#
#	include <concepts>
#	include <functional>
#	include <type_traits>
#	include "../math/almost_equal.hpp"
#	include "../trait/is_arith.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<xieite::is_arith Arith, xieite::is_invoc<bool(Arith)> Pred>
	[[nodiscard]] constexpr Arith exp_search(Pred&& pred, Arith min, std::type_identity_t<Arith> max)
	noexcept(xieite::is_noex_invoc<Pred, bool(Arith)>) {
		while (true) {
			const Arith mid = static_cast<Arith>((min + max) / 2);
			if (xieite::almost_equal(mid, min) || xieite::almost_equal(mid, max)) {
				return mid;
			}
			(std::invoke_r<bool>(pred, mid) ? max : min) = mid;
		}
	}

	template<xieite::is_arith Arith, xieite::is_invoc<bool(Arith)> Pred>
	[[nodiscard]] constexpr Arith exp_search(Pred&& pred)
	noexcept(xieite::is_noex_invoc<Pred, bool(Arith)>) {
		if constexpr (!std::unsigned_integral<Arith>) {
			if (std::invoke_r<bool>(pred, static_cast<Arith>(0))) {
				Arith mid;
				Arith min = -1;
				while (std::invoke_r<bool>(pred, min)) {
					mid = min;
					min *= 2;
				}
				return xieite::exp_search(pred, min, mid);
			}
		}
		Arith mid;
		Arith max = 1;
		while (!std::invoke_r<bool>(pred, max)) {
			mid = max;
			max *= 2;
		}
		return xieite::exp_search(pred, mid, max);
	}
}

#endif
