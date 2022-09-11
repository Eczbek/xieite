#pragma once


namespace gcufl::io::escapeCodes::prefixes {
	constexpr char decimal = '\27';
	constexpr char hexadecimal = '\x1b';
	constexpr char octal = '\033';
	constexpr char unicode = '\u001b';
}
