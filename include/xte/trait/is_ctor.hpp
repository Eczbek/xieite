#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_CTOR
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_ctor = requires { T(xte::fake<Args>()...); };
}

#endif
