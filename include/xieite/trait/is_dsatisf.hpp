#pragma once

#include "../trait/is_satisf_any.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dsatisf = !xieite::is_satisf_any<T, fns...>;
}
