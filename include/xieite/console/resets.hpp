#pragma once
#include <string_view> // std::string_view

namespace xieite::console::resets {
	constexpr std::string_view all = "\x1b[0m";
	constexpr std::string_view foreground = "\x1b[38m";
	constexpr std::string_view background = "\x1b[48m";
}
