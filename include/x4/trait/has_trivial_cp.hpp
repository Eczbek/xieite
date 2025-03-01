#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hastrivcp = std::is_trivially_copyable_v<T>;
}
