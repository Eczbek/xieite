#pragma once

#include "../trait/rmclrefreft.hpp"
#include "../trait/rmnoex.hpp"

namespace x4 {
	template<typename T>
	using rmclrefnoex = x4::rmclrefreft<x4::rmnoex<T>>;
}
