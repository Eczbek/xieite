#pragma once

#include <type_traits>
#include "../trait/add_c_referent.hpp"
#include "../trait/rm_c_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_c_referent = std::conditional_t<qual, xieite::add_c_referent<T>, xieite::rm_c_referent<T>>;
}
