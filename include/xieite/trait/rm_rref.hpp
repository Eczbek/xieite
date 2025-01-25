#pragma once

#include <type_traits>
#include "../trait/is_rref.hpp"
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_rref = std::conditional_t<xieite::is_rref<T>, xieite::rm_ref<T>, T>;
}
