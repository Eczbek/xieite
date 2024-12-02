#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_deriv_from_all = (... && std::derived_from<T, Us>);
}