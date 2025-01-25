#pragma once

#include "../trait/rm_cvlref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvlref = xieite::rm_var<xieite::rm_cvlref_referent<T>>;
}
