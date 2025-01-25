#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_lref = std::is_lvalue_reference_v<T>;
}
