#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isfn = std::is_function_v<T>;
}
