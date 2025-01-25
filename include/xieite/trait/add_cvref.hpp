#pragma once

#include "../trait/add_cv.hpp"
#include "../trait/add_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_cvref = xieite::add_cv<xieite::add_ref<T, U>>;
}
