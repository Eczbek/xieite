#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_RVALUE_REF
#
#	include "../trait/is_void.hpp"

namespace DETAIL_XTE::add_rvalue_ref {
	template<typename T>
	constexpr auto impl = ^^T&&;

	template<xte::is_void T>
	constexpr auto impl<T> = ^^T;
}

namespace xte {
	template<typename T>
	using add_rvalue_ref = [:DETAIL_XTE::add_rvalue_ref::impl<T>:];
}

#endif
