#ifndef DETAIL_XTE_HEADER_MATH_MIN
#	define DETAIL_XTE_HEADER_MATH_MIN
#
#	include "../math/less.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/assign.hpp"
#	include "../util/cast.hpp"
#	include <type_traits>

namespace xte {
	template<typename T, typename... Ts,
		typename common_type = std::common_type_t<T, Ts...>>
	[[nodiscard]] constexpr auto min(T&& first, Ts&&... rest)
	noexcept(noexcept(xte::cast<common_type>(XTE_FWD(first)))
		&& (... && requires (common_type min) {
			{ xte::less(rest, min) } noexcept;
			{ xte::assign(min, XTE_FWD(rest)) } noexcept;
		}))
	requires(requires { xte::cast<common_type>(XTE_FWD(first)); }
		&& (... && requires (common_type min) {
			xte::less(rest, min);
			xte::assign(min, XTE_FWD(rest));
		}))
	{
		auto min = xte::cast<common_type>(XTE_FWD(first));
		(..., (xte::less(rest, min) ? void(xte::assign(min, XTE_FWD(rest))) : void()));
		return min;
	}
}

#endif
