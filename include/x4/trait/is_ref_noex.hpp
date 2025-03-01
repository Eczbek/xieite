#pragma once

#include "../trait/isrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept isrefnoex = (!x4::ism_fn_ptr<T> || x4::isrefreft<T>) && x4::isnoex<T>;
}
