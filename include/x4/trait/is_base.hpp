#pragma once

#include <concepts>

namespace x4 {
	template<typename T, typename... Us>
	concept isbase = (... && std::derived_from<Us, T>);
}
