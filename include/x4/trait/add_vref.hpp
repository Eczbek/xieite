#pragma once

#include "../trait/addref.hpp"
#include "../trait/addv.hpp"

namespace x4 {
	template<typename T, typename U>
	using addvref = x4::add_v<x4::add_ref<T, U>>;
}
