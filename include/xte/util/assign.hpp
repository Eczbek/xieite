#ifndef DETAIL_XTE_HEADER_UTIL_ASSIGN
#	define DETAIL_XTE_HEADER_UTIL_ASSIGN
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_same_ignore_cvref.hpp"
#	include "../trait/remove_cvref.hpp"
#	include <type_traits>

namespace xte {
	constexpr auto assign(auto&& lhs, auto&& rhs) XTE_ARROW_CHOOSE(
		(xte::is_same_ignore_cvref<decltype(lhs), decltype(rhs)>),
		XTE_FWD(lhs) = XTE_FWD(rhs),
		XTE_FWD(lhs) = static_cast<xte::remove_cvref<decltype(lhs)>>(XTE_FWD(rhs))
	)
}

#endif
