#ifndef XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ALL
#	define XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ALL

#	include "../concepts/specialization_of.hpp"

namespace xieite::concepts {
	template<typename Type_, template<typename> typename... Templates_>
	concept SpecializationOfAll = (... && xieite::concepts::SpecializationOf<Type_, Templates_>);
}

#endif
