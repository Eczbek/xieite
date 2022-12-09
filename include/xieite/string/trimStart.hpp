#pragma once
#include <string> // std::string
#include <unordered_set> // std::unordered_set

namespace xieite::string {
	[[nodiscard]]
	std::string trimStart(const std::string& string, const char character) noexcept;

	[[nodiscard]]
	std::string trimStart(const std::string& string, const std::unordered_set<char>& characters) noexcept;
}
