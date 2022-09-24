#pragma once

#include <regex>
#include <string>
#include <string_view>
#include <vector>


namespace gcufl::string {
	std::vector<std::string> split(const std::string& string, const char delimiter) noexcept;

	std::vector<std::string> split(const std::string& string, const std::string_view delimiter = "") noexcept;

	std::vector<std::string> split(const std::string& string, const std::regex& delimiter) noexcept;
}
