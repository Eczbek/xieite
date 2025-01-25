#pragma once

#include "../trait/cp_ref.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using add_v = xieite::cp_ref<T, volatile xieite::rm_ref<T>>;
}
