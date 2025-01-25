#pragma once

#include "../trait/rm_cvref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_cvref_noex = xieite::rm_cvref_referent<xieite::rm_noex<T>>;
}
