#ifndef DETAIL_XIEITE_HEADER_DATA_CHARS
#	define DETAIL_XIEITE_HEADER_DATA_CHARS
#
#	include <cstddef>
#	include <string_view>

namespace xieite::chars {
	inline constexpr std::size_t alphabet_size = 26;

	inline constexpr std::string_view upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	inline constexpr std::string_view lower = "abcdefghijklmnopqrstuvwxyz";

	inline constexpr std::string_view digits = "0123456789";

	inline constexpr std::string_view whitespace = " \t\n\v\f\r";

	inline constexpr std::string_view alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	inline constexpr std::string_view vowels = "AEIOUaeiou";

	inline constexpr std::string_view consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
}

#endif
