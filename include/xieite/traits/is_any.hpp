#ifndef XIEITE_HEADER_TRAITS_IS_ANY
#	define XIEITE_HEADER_TRAITS_IS_ANY

#	include <type_traits>
#	include "../concepts/any.hpp"

namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsAny
	: std::bool_constant<xieite::concepts::Any<Type, Traits...>> {};
}

#endif
