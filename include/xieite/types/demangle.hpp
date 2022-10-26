#pragma once
#include <string>
#include <string_view>

namespace xieite::types {
	[[nodiscard]]
	std::string demangle(const std::string_view mangled) noexcept;
}
