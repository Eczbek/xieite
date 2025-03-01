#pragma once

#include "../trait/addlrefreft.hpp"
#include "../trait/addvarc.hpp"

namespace x4 {
	template<typename T>
	using addvarclref = x4::add_varc<x4::add_lrefreft<T>>;
}
