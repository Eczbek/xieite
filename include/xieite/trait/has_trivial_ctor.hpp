#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename... Args>
	concept has_trivial_ctor = std::is_trivially_constructible_v<T, Args...>;
}
