#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE_IMPLICIT
#	define DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE_IMPLICIT
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_castable_implicit = requires ([:^^int(U):]& f) { f(xte::fake<T>()); };
}

#endif
