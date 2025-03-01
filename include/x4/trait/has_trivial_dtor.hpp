#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hastrivdtor = std::is_trivially_destructible_v<T>;
}
