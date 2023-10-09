#ifndef XIEITE_HEADER__CONCEPTS__CHRONO_DURATION
#	define XIEITE_HEADER__CONCEPTS__CHRONO_DURATION

#	include "../traits/is_temporal_duration.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept TemporalDuration = xieite::traits::IsTemporalDuration<Type>::value;
}

#endif
