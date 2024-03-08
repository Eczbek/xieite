#ifndef XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF_ALL
#	define XIEITE_HEADER_TRAITS_IS_SPECIALIZATION_OF_ALL

#	include <type_traits>
#	include "../concepts/specialization_of_all.hpp"

namespace xieite::traits {
	template<typename Type, template<typename...> typename... Templates>
	struct IsSpecializationOfAll
	: std::bool_constant<xieite::concepts::SpecializationOfAll<Type, Templates...>> {};
}

#endif
