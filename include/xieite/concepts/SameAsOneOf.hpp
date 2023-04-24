#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename From, typename... Tos>
	concept SameAsOneOf = (std::same_as<From, Tos> || ...);
}
