#pragma once

#include "../trait/set_noex.hpp"
#include "../trait/set_var_cvlref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_cvlref_noex = xieite::set_var_cvlref<qual, xieite::set_noex<qual, T>>;
}
