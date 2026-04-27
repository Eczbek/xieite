#ifndef DETAIL_XTE_HEADER_MATH_MUL
#	define DETAIL_XTE_HEADER_MATH_MUL
#
#	include "../trait/is_number.hpp"
#	include "../trait/try_unsigned.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto mul(xte::is_number auto first, xte::is_number auto... rest) noexcept {
		using common_type = std::common_type_t<decltype(first), decltype(rest)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((static_cast<unsigned_type>(first) * ... * static_cast<unsigned_type>(rest)));
	};
}

#endif
