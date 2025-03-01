#pragma once

#include "../trait/iscrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept iscrefnoex = (!x4::ism_fn_ptr<T> || x4::iscrefreft<T>) && x4::isnoex<T>;
}
