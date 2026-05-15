#ifndef DETAIL_XTE_HEADER_UTIL_CONSTRUCT
#	define DETAIL_XTE_HEADER_UTIL_CONSTRUCT
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/address.hpp"
#	include "../util/cast.hpp"
#	include <new>

namespace xte {
	template<typename T>
	constexpr auto construct(T& object, auto&&... args) XTE_ARROW(
		*::new(xte::address(object)) T(xte::cast<T>(XTE_FWD(args)...))
	)
}

#endif
