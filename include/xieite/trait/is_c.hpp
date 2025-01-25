#pragma once

#include <type_traits>
#include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	concept is_c = std::is_const_v<xieite::rm_ref<T>>;
}
