#pragma once

#include "../trait/isrrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept isrrefnoex = (!x4::ism_fn_ptr<T> || x4::isrrefreft<T>) && x4::isnoex<T>;
}
