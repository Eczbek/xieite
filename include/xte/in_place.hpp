#ifndef DETAIL_XTE_HEADER_IN_PLACE
#	define DETAIL_XTE_HEADER_IN_PLACE
#
#	include "./address.hpp"
#	include "./class_traits.hpp"
#	include "./fundamental_traits.hpp"
#	include "./macros.hpp"
#	include "./make.hpp"
#	include "./qual_traits.hpp"
#	include <new>

namespace xte {
	template<typename object_type>
	constexpr auto construct(object_type& object, auto&&... args) XTE_RETURNS(
		*::new(xte::address(object)) object_type(xte::make<object_type>(XTE_FWD(args)...))
	)

	template<typename object_type>
	constexpr auto destroy(object_type& object) XTE_RETURNS(
		object.~object_type()
	)

	template<typename object_type, typename... arg_types>
		requires xte::is_constructible_noex<object_type, arg_types...>
	constexpr auto reconstruct(object_type& object, arg_types&&... args) XTE_RETURNS(
		xte::destroy(object),
		xte::construct(object, XTE_FWD(args)...)
	)
}

namespace DETAIL_XTE::assign {
	template<xte::is_arithmetic lhs_type>
	constexpr lhs_type& impl(lhs_type& lhs, xte::is_arithmetic auto rhs) noexcept {
		return (lhs = xte::make<lhs_type>(rhs));
	}

	template<typename lhs_type, typename rhs_type>
		requires (!xte::is_arithmetic<lhs_type> || !xte::is_arithmetic<xte::drop_ref<rhs_type>>)
	constexpr auto impl(lhs_type& lhs, rhs_type&& rhs) XTE_RETURNS_FIRST(
		(static_cast<lhs_type&>(lhs = XTE_FWD(rhs)))
		(static_cast<lhs_type&>(lhs = xte::make<lhs_type>(XTE_FWD(rhs))))
		(xte::reconstruct(lhs, XTE_FWD(rhs)))
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
		(static_cast<decltype(lhs)&>(lhs = xte::drop_cvref<decltype(lhs)>()))
		(xte::reconstruct(lhs))
	)
}

#endif
