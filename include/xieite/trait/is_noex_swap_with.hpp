#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_noex_swap_with = std::is_nothrow_swappable_with_v<T, U>;
}
