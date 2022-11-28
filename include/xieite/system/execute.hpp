#pragma once
#include <string>
#include <string_view>

namespace xieite::system {
	std::string execute(const std::string_view command, const std::size_t bufferSize = 1024) noexcept;
}
