#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept ismfnptr = std::is_member_function_pointer_v<T>;
}
