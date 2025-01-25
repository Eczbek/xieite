#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_cp_ctor = std::is_nothrow_copy_constructible_v<T>;
}
