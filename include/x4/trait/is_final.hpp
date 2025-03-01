#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isfinal = std::is_final_v<T>;
}
