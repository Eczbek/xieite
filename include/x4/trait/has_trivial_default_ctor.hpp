#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hastridfltctor = std::is_trivially_default_constructible_v<T>;
}
