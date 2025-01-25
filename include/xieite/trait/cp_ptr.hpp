#pragma once

#include "../trait/add_ptr.hpp"
#include "../trait/get_ptr.hpp"
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_ptr = xieite::add_ptr<xieite::rm_ptr<U>, xieite::get_ptr<T>>;
}
