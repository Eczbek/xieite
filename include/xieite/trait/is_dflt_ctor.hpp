#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_dflt_ctor = std::is_default_constructible_v<T>;
}