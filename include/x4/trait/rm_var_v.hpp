#pragma once

#include "../trait/rmvreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarv = x4::rmvar<x4::rmvreft<T>>;
}
