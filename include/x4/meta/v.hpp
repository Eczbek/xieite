#pragma once

#include <type_traits>

namespace x4 {
	template<auto x>
	using v = std::integral_constant<decltype(x), x>;
}
