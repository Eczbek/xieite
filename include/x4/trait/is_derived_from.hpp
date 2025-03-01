#pragma once

#include <concepts>

namespace x4 {
	template<typename T, typename... Us>
	concept isderivfrom = (... && std::derived_from<T, Us>);
}
