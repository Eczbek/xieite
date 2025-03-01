#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isboundarr = std::is_bounded_array_v<T>;
}
