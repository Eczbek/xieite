#pragma once

#include <concepts>

namespace xieite {
	template<typename T>
	concept is_arith = std::integral<T> || std::floating_point<T>;
}
