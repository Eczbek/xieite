#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_RREF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_RREF
#
#	include "../trait/is_same_ignore_cv.hpp"

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto add_rref = ^^T&&;

	template<xte::is_same_ignore_cv<void> T>
	constexpr auto add_rref<T> = ^^T;
}

namespace xte {
	template<typename T>
	using add_rref = [:DETAIL_XTE::add_rref<T>:];
}

#endif
