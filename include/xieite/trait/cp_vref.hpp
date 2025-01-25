#pragma once

#include "../trait/cp_v.hpp"
#include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vref = xieite::cp_v<T, xieite::cp_ref<T, U>>;
}
