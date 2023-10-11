#ifndef XIEITE_HEADER_TRAITS_NONE
#	define XIEITE_HEADER_TRAITS_NONE

#	include <type_traits>
#	include "../concepts/none.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct None
	: std::bool_constant<xieite::concepts::None<Type, Traits...>> {};
}

#endif
