#pragma once

#include "../trait/addcreft.hpp"
#include "../trait/addvar.hpp"

namespace x4 {
	template<typename T>
	using addvarc = x4::add_var<x4::add_creft<T>>;
}
