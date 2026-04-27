#ifndef DETAIL_XTE_HEADER_MATH_SUB
#	define DETAIL_XTE_HEADER_MATH_SUB
#
#	include "../trait/is_number.hpp"
#	include "../trait/try_unsigned.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto sub(xte::is_number auto minuend, xte::is_number auto... subtrahends) noexcept {
		using common_type = std::common_type_t<decltype(minuend), decltype(subtrahends)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((static_cast<unsigned_type>(minuend) - ... - static_cast<unsigned_type>(subtrahends)));
	}
}

#endif
