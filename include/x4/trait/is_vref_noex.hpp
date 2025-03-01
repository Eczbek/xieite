#pragma once

#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"
#include "../trait/isvrefreft.hpp"

namespace x4 {
	template<typename T>
	concept isvrefnoex = (!x4::ism_fn_ptr<T> || x4::isvrefreft<T>) && x4::isnoex<T>;
}
