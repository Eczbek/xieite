#pragma once

#include "../trait/rm_c_referent.hpp"
#include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_crref_referent = xieite::rm_c_referent<xieite::rm_rref_referent<T>>;
}
