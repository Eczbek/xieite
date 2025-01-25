#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	using rm_ref = std::remove_reference_t<T>;
}
