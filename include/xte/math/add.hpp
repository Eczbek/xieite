#ifndef DETAIL_XTE_HEADER_MATH_ADD
#	define DETAIL_XTE_HEADER_MATH_ADD
#
#	include "../trait/is_number.hpp"
#	include "../trait/try_unsigned.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto add(xte::is_number auto augend, xte::is_number auto... addends) noexcept {
		using common_type = std::common_type_t<decltype(augend), decltype(addends)...>;
		using unsigned_type = xte::try_unsigned<common_type>;
		return static_cast<common_type>((static_cast<unsigned_type>(augend) + ... + static_cast<unsigned_type>(addends)));
	};
}

#endif
