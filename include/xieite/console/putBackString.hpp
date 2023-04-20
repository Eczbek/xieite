#pragma once

#include <cstddef>
#include <iostream>
#include <string_view>

namespace xieite::console {
	inline void putBackString(const std::string_view value) noexcept {
		for (std::size_t i = value.size(); i--;)
			std::cin.putback(value[i]);
	}
}
