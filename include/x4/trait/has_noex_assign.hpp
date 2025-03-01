#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, typename U>
	concept hasnoexass = std::is_nothrow_assignable_v<T, U>;
}
