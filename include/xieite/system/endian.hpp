#ifndef XIEITE_HEADER_SYSTEM_ENDIAN
#	define XIEITE_HEADER_SYSTEM_ENDIAN

#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
#		include <bit>

namespace xieite::system::endian {
	inline constexpr bool big = (std::endian::native == std::endian::big) && (std::endian::native != std::endian::little);

	inline constexpr bool little = (std::endian::native != std::endian::big) && (std::endian::native == std::endian::little);

	inline constexpr bool mixed = (std::endian::native != std::endian::big) && (std::endian::native != std::endian::little);

	inline constexpr bool none = (std::endian::native == std::endian::big) && (std::endian::native == std::endian::little);
}

#	else
#		include "../macros/endian.hpp"

namespace xieite::system::endian {
	inline constexpr bool big = XIEITE_ENDIAN_BIG && !XIEITE_ENDIAN_LITTLE;

	inline constexpr bool little = !XIEITE_ENDIAN_BIG && XIEITE_ENDIAN_LITTLE;

	inline constexpr bool mixed = XIEITE_ENDIAN_BIG_WORD || XIEITE_ENDIAN_LITTLE_WORD;

	inline constexpr bool none = XIEITE_ENDIAN_BIG && XIEITE_ENDIAN_LITTLE;
}

#	endif
#endif

// TODO: Confirm macro versions of xieite::system::endian::mixed and xieite::system::endian::none
