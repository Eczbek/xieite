#ifndef XIEITE_HEADER__CONCEPTS__ALL_OF
#	define XIEITE_HEADER__CONCEPTS__ALL_OF

#	include "../traits/IsAllOf.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept AllOf = xieite::traits::IsAllOf<Type, Traits...>::value;
}

#endif
