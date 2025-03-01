#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hascpass = std::is_copy_assignable_v<T>;
}
