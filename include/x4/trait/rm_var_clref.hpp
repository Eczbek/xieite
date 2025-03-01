#pragma once

#include "../trait/rmclrefreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarclref = x4::rmvar<x4::rmclrefreft<T>>;
}
