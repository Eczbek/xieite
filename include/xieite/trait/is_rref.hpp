#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_rref = std::is_rvalue_reference_v<T>;
}
