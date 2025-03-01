#pragma once

#include "../trait/issatisf.hpp"

namespace x4 {
	template<typename T, auto... fns>
	concept issatisfany = (... || x4::issatisf<T, fns>);
}
