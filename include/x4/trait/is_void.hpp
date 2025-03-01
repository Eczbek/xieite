#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isvoid = std::is_void_v<T>;
}
