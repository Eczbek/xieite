#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_dtor = std::is_destructible_v<T>;
}
