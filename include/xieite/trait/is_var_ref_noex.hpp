#pragma once

#include "../trait/is_noex.hpp"
#include "../trait/is_var_ref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_ref_noex = xieite::is_var_ref<T> && xieite::is_noex<T>;
}
