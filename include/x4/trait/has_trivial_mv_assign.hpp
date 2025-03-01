#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hastrivmvass = std::is_trivially_move_assignable_v<T>;
}
