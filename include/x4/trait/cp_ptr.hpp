#pragma once

#include "../trait/addptr.hpp"
#include "../trait/getptr.hpp"
#include "../trait/rmptr.hpp"

namespace x4 {
	template<typename T, typename U>
	using cpptr = x4::add_ptr<x4::rmptr<U>, x4::get_ptr<T>>;
}
