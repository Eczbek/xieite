#pragma once

#include "../trait/iscreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept iscnoex = (!x4::ism_fn_ptr<T> || x4::iscreft<T>) && x4::isnoex<T>;
}
