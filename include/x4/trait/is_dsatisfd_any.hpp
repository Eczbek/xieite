#pragma once

#include "../trait/issatisfd_all.hpp"

namespace x4 {
	template<auto fn, typename... Ts>
	concept isdsatisfdany = !x4::issatisfd_all<fn, Ts...>;
}
