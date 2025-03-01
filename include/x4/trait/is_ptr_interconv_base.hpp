#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename U>
	concept isptrinterconvbase = std::is_pointer_interconvertible_base_of_v<T, U>;
}
