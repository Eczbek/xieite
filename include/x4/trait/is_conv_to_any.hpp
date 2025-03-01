#pragma once

#include "../trait/isconv_to.hpp"

namespace x4 {
	template<typename T, typename... Us>
	concept isconvtoany = (... || x4::isconv_to<T, Us>);
}
