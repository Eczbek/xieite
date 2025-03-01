#pragma once

#include "../trait/iscvlrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept iscvlrefnoex = (!x4::ism_fn_ptr<T> || x4::iscvlrefreft<T>) && x4::isnoex<T>;
}
