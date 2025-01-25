#pragma once

#include "../trait/set_c.hpp"
#include "../trait/set_v.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cv = xieite::set_c<qual, xieite::set_v<qual, T>>;
}
