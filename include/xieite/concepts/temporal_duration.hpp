#ifndef XIEITE_HEADER_CONCEPTS_TEMPORAL_DURATION
#	define XIEITE_HEADER_CONCEPTS_TEMPORAL_DURATION

#	include <type_traits>
#	include "../traits/is_temporal_duration.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept TemporalDuration = xieite::traits::IsTemporalDuration<std::remove_cv_t<Type>>::value;
}

#endif
