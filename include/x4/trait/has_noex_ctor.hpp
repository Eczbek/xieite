#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename... Args>
	concept hasnoexctor = std::is_nothrow_constructible_v<T, Args...>;
}
