#pragma once

#include "../trait/setlrefnoex.hpp"
#include "../trait/islrefnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cplrefnoex = x4::setlrefnoex<x4::islrefnoex<T>, U>;
}
