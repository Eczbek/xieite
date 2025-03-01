#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hascpctor = std::is_copy_constructible_v<T>;
}
