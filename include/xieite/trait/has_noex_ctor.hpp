#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename... Args>
	concept has_noex_ctor = std::is_nothrow_constructible_v<T, Args...>;
}
