#ifndef DETAIL_XTE_HEADER_UTIL_ASSIGN
#	define DETAIL_XTE_HEADER_UTIL_ASSIGN
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include <concepts>
#	include <type_traits>

namespace xte {
	constexpr auto assign(auto&& lhs, auto&& rhs) XTE_ARROW_CHOOSE(
		(std::same_as<std::remove_cvref_t<decltype(lhs)>, std::remove_cvref_t<decltype(rhs)>>),
		XTE_FWD(lhs) = XTE_FWD(rhs),
		XTE_FWD(lhs) = static_cast<std::remove_cvref_t<decltype(lhs)>>(XTE_FWD(rhs))
	)
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=123080
