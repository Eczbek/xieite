#pragma once
#include <cstddef> // std::size_t
#include <string> // std::string
#include <string_view> // std::string_view

namespace xieite::string {
	[[nodiscard]]
	std::string repeat(const std::string_view string, std::size_t count) noexcept;
}
