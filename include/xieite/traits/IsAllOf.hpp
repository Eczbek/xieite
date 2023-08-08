#ifndef XIEITE_HEADER__TRAITS__IS_ALL_OF
#	define XIEITE_HEADER__TRAITS__IS_ALL_OF

#	include <type_traits>
#	include "../concepts/AllOf.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsAllOf
	: std::bool_constant<xieite::concepts::AllOf<Type, Traits...>> {};
}

#endif
