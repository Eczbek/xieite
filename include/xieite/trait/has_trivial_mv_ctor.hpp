#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_mv_ctor = std::is_trivially_move_constructible_v<T>;
}
