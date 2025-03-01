#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename U>
	concept isnoexswapwith = std::is_nothrow_swappable_with_v<T, U>;
}
