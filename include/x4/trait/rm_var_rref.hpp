#pragma once

#include "../trait/rmrrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarrref = x4::rmvar<x4::rmrrefreft<T>>;
}
