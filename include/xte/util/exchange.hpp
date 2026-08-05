#ifndef DETAIL_XTE_HEADER_DATA_EXCHANGE
#	define DETAIL_XTE_HEADER_DATA_EXCHANGE
#
#	include "../preproc/fwd.hpp"
#	include "../trait/is_assignable_to.hpp"
#	include "../trait/is_move_constructible.hpp"
#	include "../trait/is_assignable_noex.hpp"
#	include "../trait/is_move_constructible_noex.hpp"
#	include "../util/as_xvalue.hpp"
#	include "../util/assign.hpp"

namespace xte {
	template<xte::is_move_constructible T, xte::is_assignable_to<T&> U = T>
	[[nodiscard]] constexpr T exchange(T& lhs, U&& rhs) noexcept(xte::is_move_constructible_noex<T> && xte::is_assignable_noex<T&, U>) {
		T old = T(xte::as_xvalue(lhs));
		xte::assign(lhs, XTE_FWD(rhs));
		return old;
	}
}

#endif
