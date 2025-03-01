#pragma once

#include "../trait/addcv.hpp"
#include "../trait/addref.hpp"

namespace x4 {
	template<typename T, typename U>
	using addcvref = x4::add_cv<x4::add_ref<T, U>>;
}
