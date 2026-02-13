#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_CTOR
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_noex_ctor = requires { { T(xte::fake<Args>()...) } noexcept; };
}

#endif
