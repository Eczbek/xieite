#pragma once

#include "../trait/issatisfd_any.hpp"

namespace x4 {
	template<auto fn, typename... Ts>
	concept isdsatisfdall = !x4::issatisfd_any<fn, Ts...>;
}
