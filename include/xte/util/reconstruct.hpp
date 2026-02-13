#ifndef DETAIL_XTE_HEADER_UTIL_RECONSTRUCT
#	define DETAIL_XTE_HEADER_UTIL_RECONSTRUCT
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/address.hpp"

namespace xte {
	template<typename T>
	constexpr auto reconstruct(T& object, auto&&... args) XTE_ARROW(
		object.~T(),
		*::new(xte::address(object)) T(XTE_FWD(args)...)
	);
}

#endif
