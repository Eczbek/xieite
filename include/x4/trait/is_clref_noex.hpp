#pragma once

#include "../trait/isclrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept isclrefnoex = (!x4::ism_fn_ptr<T> || x4::isclrefreft<T>) && x4::isnoex<T>;
}
