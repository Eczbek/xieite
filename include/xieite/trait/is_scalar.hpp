#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_scalar = std::is_scalar_v<T>;
}
