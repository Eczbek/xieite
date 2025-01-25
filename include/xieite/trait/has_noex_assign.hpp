#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept has_noex_assign = std::is_nothrow_assignable_v<T, U>;
}
