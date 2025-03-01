#pragma once

#include <concepts>

namespace x4 {
	template<typename T>
	concept isarith = std::integral<T> || std::floating_point<T>;
}
