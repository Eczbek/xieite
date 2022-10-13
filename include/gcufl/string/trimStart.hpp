#pragma once
#include <string>
#include <string_view>

namespace gcufl::string {
	std::string trimStart(const std::string& string, const std::string_view characters) noexcept;

	std::string trimStart(const std::string& string, const char character) noexcept;
}
