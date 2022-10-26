#pragma once
#include <cstdio>
#include <string>

namespace xieite::stream {
	[[nodiscard]]
	std::string readFile(std::FILE* const file) noexcept;
}
