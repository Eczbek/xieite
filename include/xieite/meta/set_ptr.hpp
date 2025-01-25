#pragma once

#include <cstddef>
#include "../trait/add_ptr.hpp"
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename T, std::size_t n = 1>
	using set_ptr = xieite::add_ptr<xieite::rm_ptr<T, -1uz>, n>;
}
