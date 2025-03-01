#pragma once

#include <concepts>

namespace x4 {
	template<typename T, typename... Us>
	concept isconvfrom = (... && std::convertible_to<Us, T>);
}
