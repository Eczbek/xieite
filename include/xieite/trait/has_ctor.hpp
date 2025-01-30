#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename... Args>
	concept has_ctor = std::is_constructible_v<T, Args...>;
}
