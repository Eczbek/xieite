#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isstdlayout = std::is_standard_layout_v<T>;
}
