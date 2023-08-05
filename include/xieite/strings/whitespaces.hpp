#ifndef XIEITE_HEADER__STRINGS__WHITESPACES
#	define XIEITE_HEADER__STRINGS__WHITESPACES

#	include <string_view>

namespace xieite::strings {
	inline constexpr std::string_view whitespaces = "\x9\xA\xB\xC\xD\x20\x85\xA0";
}

#endif
