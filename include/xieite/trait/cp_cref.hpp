#pragma once

#include "../trait/cp_c.hpp"
#include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cref = xieite::cp_c<T, xieite::cp_ref<T, U>>;
}
