#pragma once

#include "../trait/is_lref.hpp"
#include "../trait/rm_ref.hpp"
#include "../trait/is_v.hpp"

namespace xieite {
	template<typename T>
	concept is_vlref = xieite::is_lref<T> && xieite::is_v<xieite::rm_ref<T>>;
}
