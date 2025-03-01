#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasnoexdtor = std::is_nothrow_destructible_v<T>;
}
