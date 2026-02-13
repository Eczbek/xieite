#ifndef DETAIL_XTE_HEADER_DATA_EXCHANGE
#	define DETAIL_XTE_HEADER_DATA_EXCHANGE
#
#	include "../preproc/fwd.hpp"
#	include "../trait/is_assignable_to.hpp"
#	include "../trait/is_move_ctor.hpp"
#	include "../trait/is_noex_assignable.hpp"
#	include "../trait/is_noex_move_ctor.hpp"
#	include "../util/assign.hpp"
#	include "../util/xvalue.hpp"

namespace xte {
	template<xte::is_move_ctor T, xte::is_assignable_to<T&> U = T>
	[[nodiscard]] constexpr T exchange(T& lhs, U&& rhs) noexcept(xte::is_noex_move_ctor<T> && xte::is_noex_assignable<T&, U>) {
		T old = T(xte::xvalue(lhs));
		xte::assign(lhs, XTE_FWD(rhs));
		return old;
	}
}

#endif
