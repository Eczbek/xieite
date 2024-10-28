export module xieite:chars;

import std;

export namespace xieite::chars {
	constexpr std::size_t alphabet_size = 26;

	constexpr std::string_view upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	constexpr std::string_view lower = "abcdefghijklmnopqrstuvwxyz";

	constexpr std::string_view digits = "0123456789";

	constexpr std::string_view whitesp = "\t\n\v\f\r ";

	constexpr std::string_view alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	constexpr std::string_view vowels = "AEIOUaeiou";

	constexpr std::string_view consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
}
