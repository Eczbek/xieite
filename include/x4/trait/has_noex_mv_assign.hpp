#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasnoexmvass = std::is_nothrow_move_assignable_v<T>;
}
