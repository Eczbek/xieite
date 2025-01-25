#pragma once

#include "../trait/cp_cv.hpp"
#include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvref = xieite::cp_cv<T, xieite::cp_ref<T, U>>;
}
