#pragma once

#include <type_traits>
#include "../trait/is_lref.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_lref = std::conditional_t<xieite::is_lref<T>, xieite::rm_ref<T>, T>;
}
