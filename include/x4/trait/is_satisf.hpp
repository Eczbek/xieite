#pragma once

#include "../trait/issatisfd.hpp"

namespace x4 {
	template<typename T, auto... fns>
	concept issatisf = (... && x4::issatisfd<fns, T>);
}
