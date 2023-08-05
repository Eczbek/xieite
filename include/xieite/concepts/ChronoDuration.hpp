#ifndef XIEITE_HEADER__CONCEPTS__CHRONO_DURATION
#	define XIEITE_HEADER__CONCEPTS__CHRONO_DURATION

#	include "../traits/IsChronoDuration.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept ChronoDuration = xieite::traits::IsChronoDuration<Type>::value;
}

#endif
