#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isnoexswap = std::is_nothrow_swappable_v<T>;
}
