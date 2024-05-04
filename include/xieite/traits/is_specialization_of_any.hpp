#ifndef XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF_ANY
#	define XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF_ANY

#	include <type_traits>
#	include "../concepts/specialization_of_any.hpp"

namespace xieite::traits {
	template<typename Type_, template<typename...> typename... Templates_>
	struct IsSpecializationOfAny
	: std::bool_constant<xieite::concepts::SpecializationOfAny<Type_, Templates_...>> {};
}

#endif
