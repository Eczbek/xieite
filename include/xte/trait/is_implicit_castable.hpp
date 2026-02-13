#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CASTABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CASTABLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_implicit_castable = requires { xte::fake<int(&)(U)>()(xte::fake<T>()); };
}

#endif
