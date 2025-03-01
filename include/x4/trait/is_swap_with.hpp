#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename U>
	concept isswapwith = std::is_swappable_with_v<T, U>;
}
