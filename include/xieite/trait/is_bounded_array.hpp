#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_bounded_array = std::is_bounded_array_v<T>;
}
