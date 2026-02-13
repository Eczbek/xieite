#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_castable = requires { static_cast<U>(xte::fake<T>()); };
}

#endif
