#ifndef XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ALL
#	define XIEITE_HEADER_CONCEPTS_SPECIALIZATION_OF_ALL

#	include "../concepts/specialization_of.hpp"

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Templates>
	concept SpecializationOfAll = (... && xieite::concepts::SpecializationOf<Type, Templates>);
}

#endif
