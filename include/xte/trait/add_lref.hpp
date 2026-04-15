#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_LREF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_LREF
#
#	include "../trait/is_same_ignore_cv.hpp"

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto add_lref = ^^T&;

	template<xte::is_same_ignore_cv<void> T>
	constexpr auto add_lref<T> = ^^T;
}

namespace xte {
	template<typename T>
	using add_lref = [:DETAIL_XTE::add_lref<T>:];
}

#endif
