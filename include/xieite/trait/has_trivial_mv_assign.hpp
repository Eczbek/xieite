#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_mv_assign = std::is_trivially_move_assignable_v<T>;
}
