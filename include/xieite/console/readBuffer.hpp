#pragma once
#include <cstddef>
#include <limits>
#include <string>

namespace xieite::console {
	std::string readBuffer(const std::size_t chunkSize = 1024) noexcept;
}
