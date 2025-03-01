#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hastrivcpass = std::is_trivially_copy_assignable_v<T>;
}
