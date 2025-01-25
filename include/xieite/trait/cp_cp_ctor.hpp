#pragma once

#include <type_traits>
#include "../trait/set_cp_ctor.hpp"

namespace xieite {
	template<typename T>
	using cp_cp_ctor = xieite::set_cp_ctor<std::is_copy_constructible_v<T>>;
}
