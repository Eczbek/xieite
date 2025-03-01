#pragma once

#include "../trait/iscvrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept iscvrefnoex = (!x4::ism_fn_ptr<T> || x4::iscvrefreft<T>) && x4::isnoex<T>;
}
