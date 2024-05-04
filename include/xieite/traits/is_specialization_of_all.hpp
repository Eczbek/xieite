#ifndef XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF_ALL
#	define XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF_ALL

#	include <type_traits>
#	include "../concepts/specialization_of_all.hpp"

namespace xieite::traits {
	template<typename Type_, template<typename...> typename... Templates_>
	struct IsSpecializationOfAll
	: std::bool_constant<xieite::concepts::SpecializationOfAll<Type_, Templates_...>> {};
}

#endif
