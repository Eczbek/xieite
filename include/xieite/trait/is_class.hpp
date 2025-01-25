#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_class = std::is_class_v<T>;
}
