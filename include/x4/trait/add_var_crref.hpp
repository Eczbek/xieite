#pragma once

#include "../trait/addrrefreft.hpp"
#include "../trait/addvarc.hpp"

namespace x4 {
	template<typename T>
	using addvarcrref = x4::add_varc<x4::add_rrefreft<T>>;
}
