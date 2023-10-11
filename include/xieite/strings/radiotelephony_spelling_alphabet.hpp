#ifndef XIEITE_HEADER_STRINGS_RADIOTELEPHONY_SPELLING_ALPHABET
#	define XIEITE_HEADER_STRINGS_RADIOTELEPHONY_SPELLING_ALPHABET

#	include <array>
#	include <limits>
#	include <string_view>

namespace xieite::strings {
	inline constexpr std::array<std::string_view, std::numeric_limits<unsigned char>::max() + 1> radiotelephonySpellingAlphabet = ([] {
		std::array<std::string_view, std::numeric_limits<unsigned char>::max() + 1> result;
		result['A'] = result['a'] = "Alfa"; // This is not a typo
		result['B'] = result['b'] = "Bravo";
		result['C'] = result['c'] = "Charlie";
		result['D'] = result['d'] = "Delta";
		result['E'] = result['e'] = "Echo";
		result['F'] = result['f'] = "Foxtrot";
		result['G'] = result['g'] = "Golf";
		result['H'] = result['h'] = "Hotel";
		result['I'] = result['i'] = "India";
		result['J'] = result['j'] = "Juliett";
		result['K'] = result['k'] = "Kilo";
		result['L'] = result['l'] = "Lima";
		result['M'] = result['m'] = "Mike";
		result['N'] = result['n'] = "November";
		result['O'] = result['o'] = "Oscar";
		result['P'] = result['p'] = "Papa";
		result['Q'] = result['q'] = "Quebec";
		result['R'] = result['r'] = "Romeo";
		result['S'] = result['s'] = "Sierra";
		result['T'] = result['t'] = "Tango";
		result['U'] = result['u'] = "Uniform";
		result['V'] = result['v'] = "Victor";
		result['W'] = result['w'] = "Whiskey";
		result['X'] = result['x'] = "Xray";
		result['Y'] = result['y'] = "Yankee";
		result['Z'] = result['z'] = "Zulu";
		result['0'] = "Nadazero";
		result['1'] = "Unaone";
		result['2'] = "Bissotwo";
		result['3'] = "Terrathree";
		result['4'] = "Kartefour";
		result['5'] = "Pantafive";
		result['6'] = "Soxisix";
		result['7'] = "Setteseven";
		result['8'] = "Oktoeight";
		result['9'] = "Novenine";
		result['.'] = "Mark"; // "Dot", "Stop", "Decimal", "Point"
		result[','] = "Comma";
		result['-'] = "Dash"; // "Hyphen"
		result['/'] = "Slant";
		result['('] = "Brackets On";
		result[')'] = "Brackets Off";
		result[':'] = "Colon";
		result[';'] = "Semicolon";
		result['!'] = "Exclamation Mark";
		result['?'] = "Question Mark";
		result['\''] = "Apostrophe";
		result['"'] = "Quote";
		return result;
	})();
}

#endif
