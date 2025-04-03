#ifndef DETAIL_XIEITE_HEADER_CTNR_CH
#	define DETAIL_XIEITE_HEADER_CTNR_CH
#
#	include <cstddef>
#	include <string_view>

namespace xieite::ch {
	inline constexpr std::size_t alphabet_size = 26;

	inline constexpr std::string_view upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	inline constexpr std::string_view lower = "abcdefghijklmnopqrstuvwxyz";

	inline constexpr std::string_view digits = "0123456789";

	inline constexpr std::string_view whitesp = " \t\n\v\f\r";

	inline constexpr std::string_view alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	inline constexpr std::string_view vowels = "AEIOUaeiou";

	inline constexpr std::string_view consonants = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
}

#endif
