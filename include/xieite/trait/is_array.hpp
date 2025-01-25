#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_array = std::is_array_v<T>;
}
