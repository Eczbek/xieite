#ifndef XIEITE_HEADER__CONCEPTS__CHRONO_DURATION
#	define XIEITE_HEADER__CONCEPTS__CHRONO_DURATION

#	include "../traits/temporal_duration.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept TemporalDuration = xieite::traits::TemporalDuration<Type>::value;
}

#endif
