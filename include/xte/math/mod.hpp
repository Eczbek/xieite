#ifndef DETAIL_XTE_HEADER_MATH_MOD
#	define DETAIL_XTE_HEADER_MATH_MOD
#
#	include "../math/rem.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_number.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto mod(xte::is_number auto x, xte::is_number auto... ys) noexcept {
		using Common = std::common_type_t<decltype(x), decltype(ys)...>;
		auto result = static_cast<Common>(x);
		return (..., (result = xte::rem(xte::rem(result, ys) + static_cast<Common>(ys) * (xte::sign(result) != xte::sign(ys)), ys)));
	};
}

#endif
