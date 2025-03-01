#pragma once

#include "../trait/isrref.hpp"
#include "../trait/isv.hpp"
#include "../trait/rmref.hpp"

namespace x4 {
	template<typename T>
	concept isvrref = x4::isrref<T> && x4::isv<x4::rmref<T>>;
}
