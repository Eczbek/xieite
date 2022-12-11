#pragma once
#include <string_view> // std::string_view

namespace xieite::console::modes {
	constexpr std::string_view showCursor = "\x1b[?25h";
	constexpr std::string_view hideCursor = "\x1b[?25l";

	constexpr std::string_view saveScreen = "\x1b[?47h";
	constexpr std::string_view restoreScreen = "\x1b[?47l";

	constexpr std::string_view enableAlternativeBuffer = "\x1b[?1049h";
	constexpr std::string_view disableAlternativeBuffer = "\x1b[?1049l";
}
