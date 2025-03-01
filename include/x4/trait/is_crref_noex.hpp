#pragma once

#include "../trait/iscrrefreft.hpp"
#include "../trait/ism_fn_ptr.hpp"
#include "../trait/isnoex.hpp"

namespace x4 {
	template<typename T>
	concept iscrrefnoex = (!x4::ism_fn_ptr<T> || x4::iscrrefreft<T>) && x4::isnoex<T>;
}
