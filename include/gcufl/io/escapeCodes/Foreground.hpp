#pragma once


namespace gcufl::io::escapeCodes {
	enum struct Foreground
	: int {
		Black = 30,
		Red,
		Green,
		Yellow,
		Blue,
		Magenta,
		Cyan,
		White,
		Default = 39,
		BrightBlack = 90,
		BrightRed,
		BrightGreen,
		BrightYellow,
		BrightBlue,
		BrightMagenta,
		BrightCyan,
		BrightWhite
	};
}
