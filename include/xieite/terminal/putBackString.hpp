#pragma once

#include <cstddef>
#include <iostream>
#include <string_view>

namespace xieite::terminal {
	inline void putBackString(const std::string_view value) {
		for (std::size_t i = value.size(); i--;) {
			std::cin.putback(value[i]);
		}
	}
}
