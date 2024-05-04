#ifndef XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ANY
#	define XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ANY

#	include "../concepts/specialization_of.hpp"

namespace xieite::concepts {
	template<typename Type_, template<typename> typename... Templates_>
	concept SpecializationOfAny = (... || xieite::concepts::SpecializationOf<Type_, Templates_>);
}

#endif
