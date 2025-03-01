#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasnoexcpctor = std::is_nothrow_copy_constructible_v<T>;
}
