#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_from = (... && std::convertible_to<Us, T>);
}
