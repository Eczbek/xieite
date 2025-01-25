#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_default_ctor = std::is_trivially_default_constructible_v<T>;
}
