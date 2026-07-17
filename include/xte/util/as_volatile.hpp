#ifndef DETAIL_XTE_HEADER_UTIL_AS_VOLATILE
#	define DETAIL_XTE_HEADER_UTIL_AS_VOLATILE
#
#	include "../preproc/fwd.hpp"
#	include "../trait/add_volatile.hpp"

namespace xte {
	inline constexpr auto as_volatile = [][[nodiscard]](auto&& x) static noexcept -> xte::add_volatile<decltype(x)&&> {
		return { XTE_FWD(x) };
	};
}

#endif
