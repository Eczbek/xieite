#pragma once

#include "../trait/isvlref.hpp"
#include "../trait/isvrref.hpp"

namespace x4 {
	template<typename T>
	concept isvref = x4::isvlref<T> || x4::isvrref<T>;
}
