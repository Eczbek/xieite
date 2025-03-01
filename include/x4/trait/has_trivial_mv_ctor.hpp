#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hastrivmvctor = std::is_trivially_move_constructible_v<T>;
}
