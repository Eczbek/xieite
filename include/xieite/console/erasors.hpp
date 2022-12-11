#pragma once
#include <string_view> // std::string_view

namespace xieite::console::erasors {
	constexpr std::string_view screenFromCursor = "\x1b[0J";
	constexpr std::string_view screenUntilCursor = "\x1b[1J";
	constexpr std::string_view screen = "\x1b[2J";

	constexpr std::string_view lineFromCursor = "\x1b[0K";
	constexpr std::string_view lineUntilCursor = "\x1b[1K";
	constexpr std::string_view line = "\x1b[2K";
}
