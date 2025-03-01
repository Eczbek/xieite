#pragma once

#include "../trait/isconv_from.hpp"

namespace x4 {
	template<typename T, typename... Us>
	concept isconvfromany = (... || x4::isconv_from<T, Us>);
}
