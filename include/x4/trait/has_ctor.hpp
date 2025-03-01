#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename... Args>
	concept hasctor = std::is_constructible_v<T, Args...>;
}
