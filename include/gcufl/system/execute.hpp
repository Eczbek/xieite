#pragma once

#include <string>
#include <string_view>


namespace gcufl::system {
	std::string execute(std::string_view command) noexcept;
}
