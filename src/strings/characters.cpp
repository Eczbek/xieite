export module xieite:strings.characters;

import std;

export namespace xieite::strings::characters {
	inline constexpr std::size_t alphabetSize = 26;

	inline constexpr std::string_view uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	inline constexpr std::string_view lowercase = "abcdefghijklmnopqrstuvwxyz";

	inline constexpr std::string_view digits = "0123456789";

	inline constexpr std::string_view alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	inline constexpr std::string_view vowels = "AEIOUaeiou";

	inline constexpr std::string_view consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";

	inline constexpr std::string_view whitespaces = "\t\n\v\f\r ";
}

// TODO: Remove `inline` once wreien fixes related bug next week
