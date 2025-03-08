#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	using maybe_ref = std::conditional_t<((sizeof(T) <= (sizeof(int*) * 2)) && std::is_trivially_copyable_v<T>), T, const T&>; 
}
