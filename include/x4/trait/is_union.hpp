#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isunion = std::is_union_v<T>;
}
