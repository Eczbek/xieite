#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Any1, typename... Any2>
	concept ConvertibleToOneOf = (std::convertible_to<Any1, Any2> || ...);
}
