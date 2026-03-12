#ifndef DETAIL_XTE_HEADER_UTIL_RECONSTRUCT
#	define DETAIL_XTE_HEADER_UTIL_RECONSTRUCT
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/construct.hpp"
#	include "../util/destroy.hpp"

namespace xte {
	constexpr auto reconstruct(auto& object, auto&&... args) XTE_ARROW(
		xte::destroy(object),
		xte::construct(object, XTE_FWD(args)...)
	)
}

#endif
