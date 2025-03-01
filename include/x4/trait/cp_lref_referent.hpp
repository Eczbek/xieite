#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/setlrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cplrefreft = x4::setlrefreft<x4::islrefreft<T>, U>;
}
