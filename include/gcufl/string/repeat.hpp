#pragma once

#include <cstddef>
#include <string>
#include <string_view>


namespace gcufl::string {
	std::string repeat(const std::string_view string, std::size_t count) noexcept;
}
