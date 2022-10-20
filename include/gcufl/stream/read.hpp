#pragma once
#include <cstdio>
#include <istream>
#include <string>

namespace gcufl::stream {
	std::string read(std::istream& inputStream) noexcept;

	[[nodiscard]]
	std::string read(std::FILE* const file) noexcept;
}
