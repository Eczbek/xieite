#pragma once
#include <cstddef> // std::size_t
#include <string> // std::string

namespace xieite::console {
	std::string readBuffer(const std::size_t chunkSize = 1024) noexcept;
}
