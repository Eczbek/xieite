#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_ctor = std::is_constructible_v<T>;
}
