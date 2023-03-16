#pragma once
#include <concepts> // std::same_as

namespace xieite::concepts {
	template<typename Any1, typename... Any2>
	concept OneOf = (std::same_as<Any1, Any2> || ...);
}
