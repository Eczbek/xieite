#ifndef XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ANY
#	define XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ANY

#	include "../concepts/specialization_of.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Templates>
	concept SpecializationOfAny = (... || xieite::concepts::SpecializationOf<Type, Templates>);
}

#endif
