#pragma once

#include "../trait/rmlrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarlref = x4::rmvar<x4::rmlrefreft<T>>;
}
