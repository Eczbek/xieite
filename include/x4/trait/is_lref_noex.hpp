#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept islrefnoex = (!x4::ism_fn_ptr<T> || x4::islrefreft<T>) && x4::isnoex<T>;
}
