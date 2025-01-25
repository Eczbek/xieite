#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_dtor = std::is_trivially_destructible_v<T>;
}
