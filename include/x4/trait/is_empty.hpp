#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isempty = std::is_empty_v<T>;
}
