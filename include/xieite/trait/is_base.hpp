#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_base = (... && std::derived_from<Us, T>);
}
