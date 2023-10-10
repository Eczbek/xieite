#ifndef XIEITE_HEADER__TRAITS__IS_NOT_ALL
#	define XIEITE_HEADER__TRAITS__IS_NOT_ALL

#	include <type_traits>
#	include "../concepts/none.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsNotAll
	: std::bool_constant<xieite::concepts::NotAll<Type, Traits...>> {};
}

#endif
