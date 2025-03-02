#pragma once

#include "../trait/is_ptr_interconv_base.hpp"

namespace xieite {
	template<typename T, typename U>
	concept is_ptr_interconv_derived = xieite::is_ptr_interconv_base<U, T>;
}
