#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_mv_assign = std::is_nothrow_move_assignable_v<T>;
}
