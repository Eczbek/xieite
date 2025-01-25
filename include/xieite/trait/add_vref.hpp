#pragma once

#include "../trait/add_ref.hpp"
#include "../trait/add_v.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_vref = xieite::add_v<xieite::add_ref<T, U>>;
}
