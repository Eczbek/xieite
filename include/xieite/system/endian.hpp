#ifndef XIEITE_HEADER_SYSTEM_ENDIAN
#	define XIEITE_HEADER_SYSTEM_ENDIAN

#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
#		include <bit>
#	else
#		include "../macros/endian.hpp"
#	endif

namespace xieite::system::endian {
#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
	inline constexpr bool big = (std::endian::native == std::endian::big) && (std::endian::native != std::endian::little);
#	else
	inline constexpr bool big = XIEITE_ENDIAN_BIG && !XIEITE_ENDIAN_LITTLE;
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
	inline constexpr bool little = (std::endian::native != std::endian::big) && (std::endian::native == std::endian::little);
#	else
	inline constexpr bool little = !XIEITE_ENDIAN_BIG && XIEITE_ENDIAN_LITTLE;
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
	inline constexpr bool mixed = (std::endian::native != std::endian::big) && (std::endian::native != std::endian::little);
#	else
	inline constexpr bool mixed = XIEITE_ENDIAN_BIG_WORD || XIEITE_ENDIAN_LITTLE_WORD;
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
	inline constexpr bool none = (std::endian::native == std::endian::big) && (std::endian::native == std::endian::little);
#	else
	inline constexpr bool none = XIEITE_ENDIAN_BIG && XIEITE_ENDIAN_LITTLE;
#	endif
}

#endif

// TODO: Confirm fallback versions of xieite::system::endian::mixed and xieite::system::endian::none
