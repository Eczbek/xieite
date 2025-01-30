#pragma once

#include "../trait/is_ch.hpp"
#include "../trait/is_ptr.hpp"
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename T>
	concept is_ch_ptr = xieite::is_ptr<T> && xieite::is_ch<xieite::rm_ptr<T>>;
}
