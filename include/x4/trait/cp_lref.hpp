#pragma once

#include "../trait/islref.hpp"
#include "../trait/setlref.hpp"

namespace x4 {
	template<typename T, typename U>
	using cplref = x4::setlref<x4::islref<T>, U>;
}
