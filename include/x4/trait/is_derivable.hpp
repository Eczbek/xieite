#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isderivable = !std::is_final_v<T>;
}
