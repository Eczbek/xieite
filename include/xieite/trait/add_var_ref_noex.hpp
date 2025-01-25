#pragma once

#include "../trait/add_noex.hpp"
#include "../trait/add_var_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_ref_noex = xieite::add_var_ref<T, xieite::add_noex<U>>;
}
