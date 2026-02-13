#ifndef DETAIL_XTE_HEADER_UTIL_AS_C
#	define DETAIL_XTE_HEADER_UTIL_AS_C
#
#	include "../preproc/fwd.hpp"
#	include "../trait/add_c.hpp"

namespace xte {
	inline constexpr auto as_c = []<typename T>[[nodiscard]](T&& x) static noexcept -> xte::add_c<T&&> {
		return { XTE_FWD(x) };
	};
}

#endif
