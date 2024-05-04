#ifndef XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF
#	define XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF

#	include <type_traits>
#	include "../traits/is_specialization_of.hpp"

namespace xieite::concepts {
	template<typename Type_, template<typename...> typename Template_>
	concept SpecializationOf = xieite::traits::IsSpecializationOf<std::remove_cvref_t<Type_>, Template_>::value;
}

#endif
