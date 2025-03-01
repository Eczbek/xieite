#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isnullptr = std::is_null_pointer_v<T>;
}
