#pragma once
#include <cstddef> // std::size_t
#include <string> // std::string

namespace xieite::string {
	[[nodiscard]]
	constexpr std::string truncate(const std::string& string, const std::size_t length, const std::string& suffix = "") noexcept {
		return ((string.size() > length) ? ((suffix.size() > length) ? suffix.substr(0, length) : (string.substr(0, length - suffix.size()) + suffix)) : string);
	}
}
