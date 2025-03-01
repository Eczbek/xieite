#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasdtor  = std::is_destructible_v<T>;
}
