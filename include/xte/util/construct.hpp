#ifndef DETAIL_XTE_HEADER_UTIL_CONSTRUCT
#	define DETAIL_XTE_HEADER_UTIL_CONSTRUCT
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/address.hpp"
#	include <new>

namespace xte {
	template<typename T>
	constexpr auto construct(T& object, auto&&... args) XTE_ARROW(
		*::new(static_cast<void*>(xte::address(object))) T(XTE_FWD(args)...)
	)
}

#endif
