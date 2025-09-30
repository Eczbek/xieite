#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#
#	include "../meta/declare.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_callable = requires {
		xte::declare<T>()(xte::declare<Args>()...);
	};
}

#endif
