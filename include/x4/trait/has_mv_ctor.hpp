#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasmvctor = std::is_move_constructible_v<T>;
}
