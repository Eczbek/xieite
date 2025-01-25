#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_default_ctor = std::is_nothrow_default_constructible_v<T>;
}
