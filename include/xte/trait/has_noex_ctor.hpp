#ifndef DETAIL_XTE_HEADER_TRAIT_HAS_NOEX_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_HAS_NOEX_CTOR
#
#	include "../meta/declare.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept has_noex_ctor = requires {
		{ T(xte::declare<Args>()...) } noexcept;
	};
}

#endif
