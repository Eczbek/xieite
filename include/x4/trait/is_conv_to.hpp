#pragma once

#include <concepts>

namespace x4 {
	template<typename T, typename... Us>
	concept isconvto = (... && std::convertible_to<T, Us>);
}
