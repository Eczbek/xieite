#pragma once

#include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_satisf = (... && xieite::is_satisfd<fns, T>);
}
