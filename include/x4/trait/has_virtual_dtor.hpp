#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasvirtdtor = std::has_virtual_destructor_v<T>;
}
