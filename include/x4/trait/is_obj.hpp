#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isobj = std::is_object_v<T>;
}
