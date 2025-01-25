#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	using add_rref = std::add_rvalue_reference_t<T>;
}
