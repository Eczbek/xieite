#pragma once

#include <string>
#include <string_view>


namespace gcufl::string {
	std::string trimStart(const std::string& string, const char character) noexcept;

	std::string trimStart(const std::string& string, std::string_view characters) noexcept;
}
