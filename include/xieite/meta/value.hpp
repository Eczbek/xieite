#pragma once

#include <type_traits>

namespace xieite {
	template<auto x>
	using value = std::integral_constant<decltype(x), x>;
}
