#pragma once

#include <cstddef>
#include <string>
#include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string_view after(const std::string_view string, const std::string_view start) noexcept {
		const std::size_t index = string.find(start);
		return (index == std::string_view::npos) ? "" : string.substr(index + start.size());
	}

	[[nodiscard]] constexpr std::string_view after(const std::string_view string, const char start) noexcept {
		return xieite::strings::after(string, std::string(1, start));
	}
}
