#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept hasnoedfltctor = std::is_nothrow_default_constructible_v<T>;
}
