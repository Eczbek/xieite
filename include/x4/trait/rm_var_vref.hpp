#pragma once

#include "../trait/rmvar.hpp"
#include "../trait/rmvrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmvarvref = x4::rmvar<x4::rmvrefreft<T>>;
}
