#pragma once

#include "../trait/issatisfd.hpp"

namespace x4 {
	template<auto fn, typename... Ts>
	concept issatisfdall = (... && x4::issatisfd<fn, Ts>);
}
