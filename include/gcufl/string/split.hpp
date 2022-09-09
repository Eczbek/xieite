#pragma once

#include <string>
#include <string_view>
#include <vector>


namespace gcufl::string {
	std::vector<std::string> split(const std::string& string, const char delimiter) noexcept;

	std::vector<std::string> split(const std::string& string, std::string_view delimiter = "") noexcept;
}
