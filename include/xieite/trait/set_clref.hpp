#pragma once

#include "../trait/set_c.hpp"
#include "../trait/set_lref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_clref = xieite::set_c<qual, xieite::set_lref<qual, T>>;
}
