#pragma once

#include "../trait/isrrefreft.hpp"
#include "../trait/setrrefreft.hpp"

namespace x4 {
	template<typename T, typename U>
	using cprrefreft = x4::setrrefreft<x4::isrrefreft<T>, U>;
}
