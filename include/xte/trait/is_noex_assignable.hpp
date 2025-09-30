#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_ASSIGNABLE
#
#	include "../meta/declare.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_noex_assignable = requires {
		{ xte::declare<T>() = xte::declare<U>() } noexcept;
	};
}

#endif
