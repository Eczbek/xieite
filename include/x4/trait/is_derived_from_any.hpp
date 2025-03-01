#pragma once

#include "../trait/isderived_from.hpp"

namespace x4 {
	template<typename T, typename... Us>
	concept isderivfromany = (... || x4::isderived_from<T, Us>);
}
