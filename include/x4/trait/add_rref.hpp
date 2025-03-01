#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	using addrref = std::add_rvalue_reference_t<T>;
}
