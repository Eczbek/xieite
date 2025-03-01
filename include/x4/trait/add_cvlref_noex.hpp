#pragma once

#include "../trait/addcvlrefreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T>
	using addcvlrefnoex = x4::add_cvlrefreft<x4::addnoex<T>>;
}
