#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_empty = std::is_empty_v<T>;
}
