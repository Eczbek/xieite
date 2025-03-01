#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename U>
	concept hastrivass = std::is_trivially_assignable_v<T, U>;
}
