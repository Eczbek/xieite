#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_LVALUE_REF
#
#	include "../trait/is_void.hpp"

namespace DETAIL_XTE::add_lvalue_ref {
	template<typename T>
	constexpr auto impl = ^^T&;

	template<xte::is_void T>
	constexpr auto impl<T> = ^^T;
}

namespace xte {
	template<typename T>
	using add_lvalue_ref = [:DETAIL_XTE::add_lvalue_ref::impl<T>:];
}

#endif
