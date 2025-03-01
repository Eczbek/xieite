#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isrref = std::is_rvalue_reference_v<T>;
}
