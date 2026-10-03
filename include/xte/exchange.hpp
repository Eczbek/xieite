#ifndef DETAIL_XTE_HEADER_EXCHANGE
#	define DETAIL_XTE_HEADER_EXCHANGE
#
#	include "./assign.hpp"
#	include "./class_traits.hpp"
#	include "./macros.hpp"
#	include "./qual_traits.hpp"

namespace xte {
	template<xte::is_move_constructible lhs_type, xte::is_assignable_to<lhs_type&> rhs_type = lhs_type>
	[[nodiscard]] constexpr lhs_type exchange(lhs_type& lhs, rhs_type&& rhs)
	noexcept(xte::is_move_constructible_noex<lhs_type> && xte::is_assignable_noex<lhs_type&, rhs_type>) {
		lhs_type old = lhs_type(xte::as_xvalue(lhs));
		xte::assign(lhs, XTE_FWD(rhs));
		return old;
	}
}

#endif
