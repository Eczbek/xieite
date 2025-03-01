#pragma once

#include "../trait/islref.hpp"
#include "../trait/isrref.hpp"

namespace x4 {
	template<typename T>
	concept isref = x4::islref<T> || x4::isrref<T>;
}
