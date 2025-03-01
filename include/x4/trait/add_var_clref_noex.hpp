#pragma once

#include "../trait/addnoex.hpp"
#include "../trait/addvarclref.hpp"

namespace x4 {
	template<typename T>
	using addvarclrefnoex = x4::add_varclref<x4::addnoex<T>>;
}
