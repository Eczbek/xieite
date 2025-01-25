#pragma once

#include "../trait/is_rref.hpp"
#include "../trait/is_v.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	concept is_vrref = xieite::is_rref<T> && xieite::is_v<xieite::rm_ref<T>>;
}
