#pragma once

#include "../trait/addclrefreft.hpp"
#include "../trait/addnoex.hpp"

namespace x4 {
	template<typename T>
	using addclrefnoex = x4::add_clrefreft<x4::addnoex<T>>;
}
