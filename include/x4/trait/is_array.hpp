#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isarray = std::is_array_v<T>;
}
