#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isclass = std::is_class_v<T>;
}
