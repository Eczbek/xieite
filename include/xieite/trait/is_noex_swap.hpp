#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_noex_swap = std::is_nothrow_swappable_v<T>;
}
