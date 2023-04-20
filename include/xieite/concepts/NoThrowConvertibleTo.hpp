#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename From, typename To>
	concept NoThrowConvertibleTo = std::is_nothrow_convertible_v<From, To>;
}
