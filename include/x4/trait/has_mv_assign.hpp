#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasmvass = std::is_move_assignable_v<T>;
}
