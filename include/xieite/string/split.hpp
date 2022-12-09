#pragma once
#include <regex> // std::regex
#include <string> // std::string
#include <string_view> // std::string_view
#include <vector> // std::vector

namespace xieite::string {
	[[nodiscard]]
	std::vector<std::string> split(const std::string& string, const std::string_view delimiter = "") noexcept;

	[[nodiscard]]
	std::vector<std::string> split(const std::string& string, const char delimiter) noexcept;

	[[nodiscard]]
	std::vector<std::string> split(const std::string& string, const std::regex& delimiter) noexcept;
}
