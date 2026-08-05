#ifndef DETAIL_XTE_HEADER_UTIL_ASSIGN
#	define DETAIL_XTE_HEADER_UTIL_ASSIGN
#
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/drop_cvref.hpp"
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_same_drop_cvref.hpp"
#	include "../util/address.hpp"
#	include "../util/as_xvalue.hpp"
#	include "../util/make.hpp"
#	include "../util/reconstruct.hpp"

namespace DETAIL_XTE::assign {
	template<xte::is_arithmetic lhs_type>
	constexpr lhs_type& impl(lhs_type& lhs, xte::is_arithmetic auto rhs) {
		return (lhs = xte::make<lhs_type>(rhs));
	}

	template<typename lhs_type, typename rhs_type>
	requires(!xte::is_arithmetic<lhs_type> || !xte::is_arithmetic<xte::drop_ref<rhs_type>>)
	constexpr auto impl(lhs_type& lhs, rhs_type&& rhs) XTE_RETURNS_FIRST(
		XTE_FWD(lhs) = XTE_FWD(rhs),
		XTE_FWD(lhs) = xte::make<xte::drop_cvref<lhs_type>>(XTE_FWD(rhs)),
		xte::reconstruct(lhs, XTE_FWD(rhs)),
		xte::reconstruct(lhs, xte::make<xte::drop_cvref<lhs_type>>(XTE_FWD(rhs)))
	)
}

namespace xte {
	constexpr auto assign(auto& lhs, auto&& rhs) XTE_RETURNS_CHOOSE(
		(xte::is_same_drop_cvref<decltype(lhs), decltype(rhs)>),
		((xte::address(lhs) == xte::address(rhs))
			? lhs
			: DETAIL_XTE::assign::impl(lhs, XTE_FWD(rhs))),
		DETAIL_XTE::assign::impl(lhs, XTE_FWD(rhs))
	)

	constexpr auto assign(auto& lhs) XTE_RETURNS_FIRST(
		XTE_FWD(lhs) = xte::drop_cvref<decltype(lhs)>(),
		xte::reconstruct(lhs)
	)
}

#endif
