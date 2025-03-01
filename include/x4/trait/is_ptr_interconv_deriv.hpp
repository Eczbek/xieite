#pragma once

#include "../trait/isptr_interconv_base.hpp"

namespace x4 {
	template<typename T, typename U>
	concept isptrinterconvderiv = x4::isptr_interconv_base<U, T>;
}
