#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_dtor = std::is_nothrow_destructible_v<T>;
}
