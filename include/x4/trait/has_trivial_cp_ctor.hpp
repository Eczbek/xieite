#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hastrivcpctor = std::is_trivially_copy_constructible_v<T>;
}
