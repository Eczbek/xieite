#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isswap = std::is_swappable_v<T>;
}
