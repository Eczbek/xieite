#pragma once

#include "../trait/addvreft.hpp"
#include "../trait/addvar.hpp"

namespace x4 {
	template<typename T>
	using addvarv = x4::add_var<x4::add_vreft<T>>;
}
