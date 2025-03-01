#pragma once

#include "../trait/setcnoex.hpp"
#include "../trait/iscnoex.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpcnoex = x4::setcnoex<x4::iscnoex<T>, U>;
}
