#pragma once

#include <string>
#include <string_view>


namespace gcufl::file {
	std::string read(const std::string_view path) noexcept;
}
