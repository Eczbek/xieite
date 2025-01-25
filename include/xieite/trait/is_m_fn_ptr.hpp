#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_m_fn_ptr = std::is_member_function_pointer_v<T>;
}
