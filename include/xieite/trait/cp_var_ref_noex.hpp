#pragma once

#include "../trait/cp_var_ref.hpp"
#include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_ref_noex = xieite::cp_var_ref<T, xieite::cp_noex<T, U>>;
}
