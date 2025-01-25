#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_unbounded_array = std::is_unbounded_array_v<T>;
}
