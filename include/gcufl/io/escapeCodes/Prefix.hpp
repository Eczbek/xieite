#pragma once


namespace gcufl::io::escapeCodes {
	enum struct Prefix
	: char {
		Decimal = '\27',
		Hexadecimal = '\x1b',
		Octal = '\033',
		Unicode = '\u001b'
	};
}
