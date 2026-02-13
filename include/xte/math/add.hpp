#ifndef DETAIL_XTE_HEADER_MATH_ADD
#	define DETAIL_XTE_HEADER_MATH_ADD
#
#	include "../math/try_unsigned.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto add(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		using Unsigned = xte::try_unsigned<Common>;
		return static_cast<Common>((static_cast<Unsigned>(x) + ... + static_cast<Unsigned>(ys)));
	};
}

#endif
