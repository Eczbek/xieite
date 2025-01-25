#pragma once

#include "../trait/rm_ref.hpp"
#include "../trait/rm_v.hpp"

namespace xieite {
	template<typename T>
	using rm_vref = xieite::rm_v<xieite::rm_ref<T>>;
}
