#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Source, typename Target>
	concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<Source, Target>;
}
