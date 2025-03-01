#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isaggr = std::is_aggregate_v<T>;
}
