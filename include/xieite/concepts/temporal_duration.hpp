#pragma once

#include "../traits/temporal_duration.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept TemporalDuration = xieite::traits::TemporalDuration<Type>::value;
}
