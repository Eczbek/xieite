#pragma once

#include <array>
#include <limits>
#include <string>
#include <string_view>
#include <vector>


namespace gcufl::string {
	std::vector<std::string> split(const std::string& string, std::string_view delimiter) noexcept;

	std::vector<std::string> split(const std::string& string, const char delimiter) noexcept;

	std::string trunc(const std::string& string, const std::size_t length, const std::string& suffix = "...") noexcept;

	std::string trimStart(const std::string& string, const char character) noexcept;

	std::string trimStart(const std::string& string, std::string_view characters) noexcept;

	std::string trimEnd(const std::string& string, const char character) noexcept;

	std::string trimEnd(const std::string& string, std::string_view characters) noexcept;
}
