#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept has_trivial_assign = std::is_trivially_assignable_v<T, U>;
}
