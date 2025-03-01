#pragma once

#include "../trait/addlrefreft.hpp"
#include "../trait/addvarv.hpp"

namespace x4 {
	template<typename T>
	using addvarvlref = x4::add_varv<x4::add_lrefreft<T>>;
}
