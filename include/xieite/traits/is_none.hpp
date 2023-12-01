#ifndef XIEITE_HEADER_TRAITS_IS_NONE
#	define XIEITE_HEADER_TRAITS_IS_NONE

#	include <type_traits>
#	include "../concepts/none.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsNone
	: std::bool_constant<xieite::concepts::None<Type, Traits...>> {};
}

#endif
