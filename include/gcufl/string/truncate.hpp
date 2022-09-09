#pragma once

#include <cstddef>
#include <string>


namespace gcufl::string {
	std::string truncate(const std::string& string, const std::size_t length, const std::string& suffix = "") noexcept;
}
