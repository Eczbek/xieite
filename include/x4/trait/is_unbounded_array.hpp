#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isunboundarr = std::is_unbounded_array_v<T>;
}
