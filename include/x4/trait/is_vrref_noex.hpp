#pragma once

#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"
#include "../trait/isvrrefreft.hpp"

namespace x4 {
	template<typename T>
	concept isvrrefnoex = (!x4::ism_fn_ptr<T> || x4::isvrrefreft<T>) && x4::isnoex<T>;
}
