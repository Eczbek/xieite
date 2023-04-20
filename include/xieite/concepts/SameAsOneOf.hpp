#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Any1, typename... Any2>
	concept SameAsOneOf = (std::same_as<Any1, Any2> || ...);
}
