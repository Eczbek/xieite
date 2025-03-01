#pragma once

#include "../trait/isclref.hpp"
#include "../trait/iscrref.hpp"

namespace x4 {
	template<typename T>
	concept iscref = x4::isclref<T> || x4::iscrref<T>;
}
