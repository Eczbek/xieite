#ifndef DETAIL_XTE_HEADER_MATH_MAX
#	define DETAIL_XTE_HEADER_MATH_MAX
#
#	include "../math/less.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/assign.hpp"
#	include "../util/make.hpp"
#	include <type_traits>

namespace xte {
	template<typename first_type, typename... rest_types,
		typename common_type = std::common_type_t<first_type, rest_types...>>
	[[nodiscard]] constexpr auto max(first_type&& first, rest_types&&... rest)
	noexcept(noexcept(common_type(XTE_FWD(first)))
		&& (... && requires (common_type max) {
			{ xte::less(max, rest) } noexcept;
			{ xte::assign(max, XTE_FWD(rest)) } noexcept;
		}))
	requires(requires { common_type(XTE_FWD(first)); }
		&& (... && requires (common_type max) {
			xte::less(max, rest);
			xte::assign(max, XTE_FWD(rest));
		}))
	{
		auto max = xte::make<common_type>(XTE_FWD(first));
		(..., (xte::less(max, rest) ? void(xte::assign(max, XTE_FWD(rest))) : void()));
		return max;
	}
}

#endif
