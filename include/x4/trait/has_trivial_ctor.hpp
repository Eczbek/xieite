#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename... Args>
	concept hastrivctor = std::is_trivially_constructible_v<T, Args...>;
}
