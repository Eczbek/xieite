#pragma once

#include <cstddef>
#include "../trait/addptr.hpp"
#include "../trait/rmptr.hpp"

namespace x4 {
	template<typename T, std::size_t n = 1>
	using setptr = x4::add_ptr<x4::rmptr<T, -1uz>, n>;
}
