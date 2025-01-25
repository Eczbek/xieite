#pragma once

#include <type_traits>
#include "../trait/set_cp_assign.hpp"

namespace xieite {
	template<typename T>
	using cp_cp_assign = xieite::set_cp_assign<std::is_copy_assignable_v<T>>;
}
