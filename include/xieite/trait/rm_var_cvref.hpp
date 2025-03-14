#pragma once

#include "../trait/rm_cvref_referent.hpp"
#include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvref = xieite::rm_var<xieite::rm_cvref_referent<T>>;
}
