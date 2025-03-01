#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isscalar = std::is_scalar_v<T>;
}
