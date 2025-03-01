#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isfundamental = std::is_fundamental_v<T>;
}
