#pragma once

#include <string>
#include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view before(const std::string_view string, const std::string_view end) noexcept {
		return string.substr(0, string.find(end));
	}

	[[nodiscard]] constexpr std::string_view before(const std::string_view string, const char end) noexcept {
		return xieite::strings::before(string, std::string(1, end));
	}
}
