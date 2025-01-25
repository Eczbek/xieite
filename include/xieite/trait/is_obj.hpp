#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_obj = std::is_object_v<T>;
}
