#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	using add_lref = std::add_lvalue_reference_t<T>;
}
