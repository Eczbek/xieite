#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept ismobjptr = std::is_member_object_pointer_v<T>;
}
