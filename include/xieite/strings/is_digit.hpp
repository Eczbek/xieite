#pragma once

#include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr bool isDigit(const char character) noexcept {
		return std::string_view("0123456789").contains(character);
	}
}
