#pragma once

#include <type_traits>
#include "../trait/setmvctor.hpp"

namespace x4 {
	template<typename T>
	using cpmvctor = x4::setmvctor<std::is_move_constructible_v<T>>;
}
