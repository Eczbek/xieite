#pragma once
#include <cstdio>
#include <string>

namespace gcufl::stream {
	[[nodiscard]]
	std::string readFile(std::FILE* const file) noexcept;
}
