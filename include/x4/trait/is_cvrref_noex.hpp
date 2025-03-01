#pragma once

#include "../trait/iscvrrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept iscvrrefnoex = (!x4::ism_fn_ptr<T> || x4::iscvrrefreft<T>) && x4::isnoex<T>;
}
