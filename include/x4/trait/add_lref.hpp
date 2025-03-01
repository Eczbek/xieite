#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	using addlref = std::add_lvalue_reference_t<T>;
}
