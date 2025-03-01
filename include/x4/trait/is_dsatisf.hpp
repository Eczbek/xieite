#pragma once

#include "../trait/issatisf_any.hpp"

namespace x4 {
	template<typename T, auto... fns>
	concept isdsatisf = !x4::issatisf_any<T, fns...>;
}
