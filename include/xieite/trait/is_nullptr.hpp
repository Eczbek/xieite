#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nullptr = std::is_null_pointer_v<T>;
}
