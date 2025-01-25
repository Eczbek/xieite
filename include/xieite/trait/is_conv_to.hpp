#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_to = (... && std::convertible_to<T, Us>);
}
