#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_cp_assign = std::is_nothrow_copy_assignable_v<T>;
}
