#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_default_ctor = std::is_default_constructible_v<T>;
}
