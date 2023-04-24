#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept ConvertibleToOneOf = (std::convertible_to<From, Tos> || ...);
}
