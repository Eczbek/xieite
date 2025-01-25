#pragma once

#include "../trait/is_satisfd.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfd_all = (... && xieite::is_satisfd<fn, Ts>);
}
