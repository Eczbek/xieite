#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE
#
#	include "../meta/declare.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_assignable = requires {
		xte::declare<T>() = xte::declare<U>();
	};
}

#endif
