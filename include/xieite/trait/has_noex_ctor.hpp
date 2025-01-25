#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_ctor = std::is_nothrow_constructible_v<T>;
}
