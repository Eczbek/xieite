#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_fn = std::is_function_v<T>;
}
