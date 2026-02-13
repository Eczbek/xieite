#ifndef DETAIL_XTE_HEADER_UTIL_AS_V
#	define DETAIL_XTE_HEADER_UTIL_AS_V
#
#	include "../preproc/fwd.hpp"
#	include "../trait/add_v.hpp"

namespace xte {
	inline constexpr auto as_v = []<typename T>[[nodiscard]](T&& x) static noexcept -> xte::add_v<T&&> {
		return { XTE_FWD(x) };
	};
}

#endif
