#pragma once

#include "../trait/rm_cv.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_cvref = xieite::rm_cv<xieite::rm_ref<T>>;
}
