#pragma once

#include <cstdio>
#include <istream>
#include <string>


namespace gcufl::stream {
	std::string read(std::istream& inputStream) noexcept;

	std::string read(std::FILE* file) noexcept;
}
