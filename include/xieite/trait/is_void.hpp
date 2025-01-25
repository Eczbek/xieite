#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_void = std::is_void_v<T>;
}
