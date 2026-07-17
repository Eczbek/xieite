#ifndef DETAIL_XTE_HEADER_UTIL_AS_CONST
#	define DETAIL_XTE_HEADER_UTIL_AS_CONST
#
#	include "../preproc/fwd.hpp"
#	include "../trait/add_const.hpp"

namespace xte {
	inline constexpr auto as_const = [][[nodiscard]](auto&& x) static noexcept -> xte::add_const<decltype(x)&&> {
		return { XTE_FWD(x) };
	};
}

#endif
