#pragma once

#include "../trait/rmcreft.hpp"
#include "../trait/rmlrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmclrefreft = x4::rmcreft<x4::rmlrefreft<T>>;
}
