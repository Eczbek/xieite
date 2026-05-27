#ifndef DETAIL_XTE_HEADER_MATH_MAX
#	define DETAIL_XTE_HEADER_MATH_MAX
#
#	include "../math/less.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/assign.hpp"
#	include "../util/cast.hpp"
#	include <type_traits>

namespace xte {
	template<typename T, typename... Ts,
		typename common_type = std::common_type_t<T, Ts...>>
	[[nodiscard]] constexpr auto max(T&& first, Ts&&... rest)
	noexcept(noexcept(xte::cast<common_type>(XTE_FWD(first)))
		&& (... && requires (common_type max) {
			{ xte::less(max, rest) } noexcept;
			{ xte::assign(max, XTE_FWD(rest)) } noexcept;
		}))
	requires(requires { xte::cast<common_type>(XTE_FWD(first)); }
		&& (... && requires (common_type max) {
			xte::less(max, rest);
			xte::assign(max, XTE_FWD(rest));
		}))
	{
		auto max = xte::cast<common_type>(XTE_FWD(first));
		(..., (xte::less(max, rest) ? void(xte::assign(max, XTE_FWD(rest))) : void()));
		return max;
	}
}

#endif
