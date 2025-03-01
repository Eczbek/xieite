#pragma once

#include "../trait/addlrefreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T>
	using addlrefnoex = x4::add_lrefreft<x4::addnoex<T>>;
}
