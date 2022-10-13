#pragma once
#include <istream>
#include <string_view>

namespace gcufl::stream {
	std::istream& putBack(std::istream& inputStream, const std::string_view data) noexcept;
}
