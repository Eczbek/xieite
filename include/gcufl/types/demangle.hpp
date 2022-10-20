#pragma once
#include <string>
#include <string_view>

namespace gcufl::types {
	[[nodiscard]]
	std::string demangle(const std::string_view mangled) noexcept;
}
