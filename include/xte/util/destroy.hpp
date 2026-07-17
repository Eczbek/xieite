#ifndef DETAIL_XTE_HEADER_UTIL_DESTROY
#	define DETAIL_XTE_HEADER_UTIL_DESTROY
#
#	include "../preproc/returns.hpp"

namespace xte {
	template<typename T>
	constexpr auto destroy(T& object) XTE_RETURNS(
		object.~T()
	)
}

#endif
