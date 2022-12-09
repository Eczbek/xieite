#pragma once
#include <string> // std::string
#include <string_view> // std::string_view

namespace xieite::types {
	[[nodiscard]]
	std::string demangle(const std::string_view mangled) noexcept;
}
