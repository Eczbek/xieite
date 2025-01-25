#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_derived_from = (... && std::derived_from<T, Us>);
}
