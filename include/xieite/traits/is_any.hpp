#ifndef XIEITE_HEADER_TRAITS_IS_ANY
#	define XIEITE_HEADER_TRAITS_IS_ANY

#	include <type_traits>
#	include "../concepts/any.hpp"

namespace xieite::traits {
	template<typename Type_, template<typename> typename... Traits_>
	struct IsAny
	: std::bool_constant<xieite::concepts::Any<Type_, Traits_...>> {};
}

#endif
