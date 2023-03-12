#pragma once
#include <concepts> // std::same_as

namespace xieite::concepts {
	template<typename T, typename... VV>
	concept OneOf = (std::same_as<T, VV> || ...);
}
