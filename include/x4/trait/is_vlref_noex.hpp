#pragma once

#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"
#include "../trait/isvlrefreft.hpp"

namespace x4 {
	template<typename T>
	concept isvlrefnoex = (!x4::ism_fn_ptr<T> || x4::isvlrefreft<T>) && x4::isnoex<T>;
}
