#pragma once

#include "../trait/set_c_referent.hpp"
#include "../trait/set_rref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_crref_referent = xieite::set_c_referent<qual, xieite::set_rref_referent<qual, T>>;
}
