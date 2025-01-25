#pragma once

#include <type_traits>
#include "../trait/set_mv_assign.hpp"

namespace xieite {
	template<typename T>
	using cp_mv_assign = xieite::set_mv_assign<std::is_move_assignable_v<T>>;
}
