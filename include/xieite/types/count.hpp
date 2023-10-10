#pragma once

#include <cstddef>

namespace xieite::types {
	template<typename... Types>
	inline constexpr std::size_t count = sizeof...(Types);
}
