#ifndef DETAIL_XTE_HEADER_MATH_MAX
#	define DETAIL_XTE_HEADER_MATH_MAX
#
#	include "../math/less.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/assign.hpp"
#	include "../util/cast.hpp"
#	include "../util/xvalue.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto max(auto&& first, auto&&... rest) XTE_ARROW(
		([](auto max, auto&&... rest) XTE_ARROW(
			(..., void(xte::less(max, rest) ? xte::assign(max, XTE_FWD(rest)) : max)), auto(xte::xvalue(max))
		))(xte::cast<std::common_type_t<decltype(first), decltype(rest)...>>(XTE_FWD(first)), XTE_FWD(rest)...)
	)
}

#endif
