#ifndef XIEITE_HEADER__CONCEPTS__ANY_OF
#	define XIEITE_HEADER__CONCEPTS__ANY_OF

#	include "../traits/IsAnyOf.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept AnyOf = xieite::traits::IsAnyOf<Type, Traits...>::value;
}

#endif
