#ifndef XIEITE_HEADER_CONCEPTS_TEMPORAL_DURATION
#	define XIEITE_HEADER_CONCEPTS_TEMPORAL_DURATION

#	include "../traits/is_temporal_duration.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept TemporalDuration = xieite::traits::IsTemporalDuration<Type>::value; // Usage to be replaced with std::specialization_of in C++26
}

#endif
