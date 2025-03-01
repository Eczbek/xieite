#pragma once

#include "../trait/addcreft.hpp"
#include "../trait/addlrefreft.hpp"

namespace x4 {
	template<typename T>
	using addclrefreft = x4::add_creft<x4::add_lrefreft<T>>;
}
