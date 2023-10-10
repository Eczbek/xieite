#ifndef XIEITE_HEADER__TRAITS__IS_NONE
#	define XIEITE_HEADER__TRAITS__IS_NONE

#	include <type_traits>
#	include "../concepts/none.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsNone
	: std::bool_constant<xieite::concepts::None<Type, Traits...>> {};
}

#endif
