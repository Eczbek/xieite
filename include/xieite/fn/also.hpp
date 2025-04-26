#ifndef DETAIL_XIEITE_HEADER_FN_ALSO
#	define DETAIL_XIEITE_HEADER_FN_ALSO
#
#	include <concepts>
#	include <functional>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/has_cp_ctor.hpp"
#	include "../trait/has_noex_cp_ctor.hpp"
#	include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<xieite::has_cp_ctor T, std::invocable<T&&> Fn>
	[[nodiscard]] constexpr T also(T&& x, Fn&& fn = {})
	noexcept(xieite::has_noex_cp_ctor<T> && xieite::is_noex_invoc<Fn, void(T&&)>) {
		const T copy = x;
		std::invoke(XIEITE_FWD(fn), x);
		return copy;
	}

	template<xieite::has_cp_ctor T, std::invocable<> Fn>
	[[nodiscard]] constexpr T also(T&& x, Fn&& fn = {})
	noexcept(xieite::has_noex_cp_ctor<T> && xieite::is_noex_invoc<Fn>) {
		return xieite::also(XIEITE_FWD(x), [&]() XIEITE_ARROW(std::invoke(XIEITE_FWD(fn))));
	}
}

#endif
