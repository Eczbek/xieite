#pragma once

#include <string>
#include <string_view>


namespace gcufl::string {
	std::string trimEnd(const std::string& string, const char character) noexcept;

	std::string trimEnd(const std::string& string, const std::string_view characters) noexcept;
}
