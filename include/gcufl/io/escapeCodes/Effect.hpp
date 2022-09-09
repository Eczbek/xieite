#pragma once


namespace gcufl::io::escapeCodes {
	enum struct Effect
	: int {
		Bold = 1,
		Dim,
		Italic,
		Underline,
		Blink,
		Inverse = 7,
		Invisible,
		Strikethrough,
		NoBold = 22,
		NoDim = 22,
		NoItalic,
		NoUnderline,
		NoBlink,
		NoInverse = 27,
		NoInvisible,
		NoStrikethrough
	};
}
