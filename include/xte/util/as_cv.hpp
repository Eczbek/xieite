#ifndef DETAIL_XTE_HEADER_UTIL_AS_CV
#	define DETAIL_XTE_HEADER_UTIL_AS_CV
#
#	include "../preproc/fwd.hpp"
#	include "../trait/add_cv.hpp"

namespace xte {
	inline constexpr auto as_cv = [][[nodiscard]](auto&& x) static noexcept -> xte::add_cv<decltype(x)&&> {
		return { XTE_FWD(x) };
	};
}

#endif
