#pragma once

#include "../trait/rmclrefreft.hpp"
#include "../trait/rmrrefreft.hpp"

namespace x4 {
	template<typename T>
	using rmcrefreft = x4::rmclrefreft<x4::rmrrefreft<T>>;
}
