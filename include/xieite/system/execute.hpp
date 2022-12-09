#pragma once
#include <cstddef> // std::size_t
#include <string> // std::string
#include <string_view> // std::string_view

namespace xieite::system {
	std::string execute(const std::string_view command, const std::size_t chunkSize = 1024) noexcept;
}
