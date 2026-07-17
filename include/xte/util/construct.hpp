#ifndef DETAIL_XTE_HEADER_UTIL_CONSTRUCT
#	define DETAIL_XTE_HEADER_UTIL_CONSTRUCT
#
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../util/address.hpp"
#	include "../util/make.hpp"
#	include <new>

namespace xte {
	template<typename T>
	constexpr auto construct(T& object, auto&&... args) XTE_RETURNS(
		*::new(xte::address(object)) T(xte::make<T>(XTE_FWD(args)...))
	)
}

#endif
