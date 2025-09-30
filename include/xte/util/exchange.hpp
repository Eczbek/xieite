#ifndef DETAIL_XTE_HEADER_UTIL_EXCHANGE
#	define DETAIL_XTE_HEADER_UTIL_EXCHANGE
#
#	include "../preproc/fwd.hpp"
#	include "../trait/has_implicit_move_ctor.hpp"
#	include "../trait/has_noex_implicit_move_ctor.hpp"
#	include "../trait/is_assignable_to.hpp"
#	include "../trait/is_noex_assignable.hpp"
#	include "../util/move.hpp"

namespace xte {
	template<xte::has_implicit_move_ctor T, xte::is_assignable_to<T&> U = T>
	[[nodiscard]] constexpr T exchange(T& lhs, U&& rhs)
	noexcept(xte::has_noex_implicit_move_ctor<T> && xte::is_noex_assignable<T&, U>) {
		T old = xte::move(lhs);
		lhs = XTE_FWD(rhs);
		return old;
	}
}

#endif
