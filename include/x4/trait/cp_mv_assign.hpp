#pragma once

#include <type_traits>
#include "../trait/setmvass.hpp"

namespace x4 {
	template<typename T>
	using cpmvass = x4::setmvass<std::is_move_assignable_v<T>>;
}
