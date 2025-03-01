#pragma once

#include "../trait/addcreft.hpp"
#include "../trait/addrrefreft.hpp"

namespace x4 {
	template<typename T>
	using addcrrefreft = x4::add_creft<x4::add_rrefreft<T>>;
}
