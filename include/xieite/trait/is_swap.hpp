#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_swap = std::is_swappable_v<T>;
}
