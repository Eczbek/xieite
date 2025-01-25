#pragma once

#include <type_traits>

namespace xieite {
	template<auto x>
	using v = std::integral_constant<decltype(x), x>;
}
