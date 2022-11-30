#pragma once
#include <set>
#include <string>

namespace xieite::string {
	[[nodiscard]]
	std::string trimStart(const std::string& string, const char character) noexcept;

	[[nodiscard]]
	std::string trimStart(const std::string& string, const std::set<char>& characters) noexcept;
}
