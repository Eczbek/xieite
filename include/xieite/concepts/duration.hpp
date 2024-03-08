#ifndef XIEITE_HEADER_CONCEPTS_DURATION
#	define XIEITE_HEADER_CONCEPTS_DURATION

#	include <type_traits>
#	include "../traits/is_duration.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Duration = xieite::traits::IsDuration<std::remove_cv_t<Type>>::value;
}

#endif
