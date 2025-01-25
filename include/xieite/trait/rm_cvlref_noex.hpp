#pragma once

#include "../trait/rm_cvlref_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_cvlref_noex = xieite::rm_cvlref_referent<xieite::rm_noex<T>>;
}
