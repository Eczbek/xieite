#pragma once

#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"
#include "../trait/isvreft.hpp"

namespace x4 {
	template<typename T>
	concept isvnoex = (!x4::ism_fn_ptr<T> || x4::isvreft<T>) && x4::isnoex<T>;
}
