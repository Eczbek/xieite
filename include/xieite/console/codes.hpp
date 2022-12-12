#pragma once
#include <string_view>

namespace xieite::console {
	constexpr std::string_view enableBold = "\x1b[1m";
	constexpr std::string_view enableDim = "\x1b[2m";
	constexpr std::string_view enableItalic = "\x1b[3m";
	constexpr std::string_view enableUnderline = "\x1b[4m";
	constexpr std::string_view enableBlink = "\x1b[5m";
	constexpr std::string_view enableInverse = "\x1b[7m";
	constexpr std::string_view enableInvisible = "\x1b[8m";
	constexpr std::string_view enableStrikethrough = "\x1b[9m";
	constexpr std::string_view disableBold = "\x1b[21m";
	constexpr std::string_view disableDim = "\x1b[22m";
	constexpr std::string_view disableItalic = "\x1b[23m";
	constexpr std::string_view disableUnderline = "\x1b[24m";
	constexpr std::string_view disableBlink = "\x1b[25m";
	constexpr std::string_view disableInverse = "\x1b[27m";
	constexpr std::string_view disableInvisible = "\x1b[28m";
	constexpr std::string_view disableStrikethrough = "\x1b[29m";

	constexpr std::string_view eraseScreenFromCursor = "\x1b[0J";
	constexpr std::string_view eraseScreenUntilCursor = "\x1b[1J";
	constexpr std::string_view eraseScreen = "\x1b[2J";
	constexpr std::string_view eraseLineFromCursor = "\x1b[0K";
	constexpr std::string_view eraseLineUntilCursor = "\x1b[1K";
	constexpr std::string_view eraseLine = "\x1b[2K";

	constexpr std::string_view showCursor = "\x1b[?25h";
	constexpr std::string_view hideCursor = "\x1b[?25l";
	constexpr std::string_view saveScreen = "\x1b[?47h";
	constexpr std::string_view restoreScreen = "\x1b[?47l";
	constexpr std::string_view enableAlternativeBuffer = "\x1b[?1049h";
	constexpr std::string_view disableAlternativeBuffer = "\x1b[?1049l";

	constexpr std::string_view resetColors = "\x1b[0m";
	constexpr std::string_view resetForeground = "\x1b[38m";
	constexpr std::string_view resetBackground = "\x1b[48m";
}
