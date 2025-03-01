#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasnoexmvctor = std::is_nothrow_move_constructible_v<T>;
}
