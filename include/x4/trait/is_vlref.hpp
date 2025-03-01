#pragma once

#include "../trait/islref.hpp"
#include "../trait/rmref.hpp"
#include "../trait/isv.hpp"

namespace x4 {
	template<typename T>
	concept isvlref = x4::islref<T> && x4::isv<x4::rmref<T>>;
}
