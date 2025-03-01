#pragma once

#include "../trait/rmc.hpp"
#include "../trait/rmlref.hpp"

namespace x4 {
	template<typename T>
	using rmclref = x4::rmc<x4::rmlref<T>>;
}
