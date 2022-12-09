#pragma once
#include <cstddef> // std::size_t
#include <string> // std::string

namespace xieite::string {
	[[nodiscard]]
	std::string truncate(const std::string& string, const std::size_t length, const std::string& suffix = "") noexcept;
}
