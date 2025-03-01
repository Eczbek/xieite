#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasnoexcpass = std::is_nothrow_copy_assignable_v<T>;
}
