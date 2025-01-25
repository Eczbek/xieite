#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_mv_ctor = std::is_move_constructible_v<T>;
}
