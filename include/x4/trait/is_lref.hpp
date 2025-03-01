#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept islref = std::is_lvalue_reference_v<T>;
}
