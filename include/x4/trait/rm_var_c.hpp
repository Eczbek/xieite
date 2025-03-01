#pragma once

#include "../trait/rmcreft.hpp"
#include "../trait/rmvar.hpp"

namespace x4 {
	template<typename T>
	using rmvarc = x4::rmvar<x4::rmcreft<T>>;
}
