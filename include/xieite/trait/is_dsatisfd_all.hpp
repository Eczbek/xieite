#pragma once

#include "../trait/is_satisfd_any.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd_all = !xieite::is_satisfd_any<fn, Ts...>;
}
