#pragma once

#include "../trait/iscvreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept iscvnoex = (!x4::ism_fn_ptr<T> || x4::iscvreft<T>) && x4::isnoex<T>;
}
