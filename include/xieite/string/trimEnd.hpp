#pragma once
#include <string>
#include <string_view>

namespace xieite::string {
	[[nodiscard]]
	std::string trimEnd(const std::string& string, const std::string_view characters) noexcept;

	[[nodiscard]]
	std::string trimEnd(const std::string& string, const char character) noexcept;
}
