#ifndef XIEITE_HEADER__TRAITS__IS_ANY_OF
#	define XIEITE_HEADER__TRAITS__IS_ANY_OF

#	include <type_traits>
#	include "../concepts/any_of.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsAnyOf
	: std::bool_constant<xieite::concepts::AnyOf<Type, Traits...>> {};
}

#endif
