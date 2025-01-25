#pragma once

#include "../trait/rm_c.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_cref = xieite::rm_c<xieite::rm_ref<T>>;
}
