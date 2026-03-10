#ifndef DETAIL_XTE_HEADER_UTIL_DESTROY
#	define DETAIL_XTE_HEADER_UTIL_DESTROY
#
#	include "../preproc/arrow.hpp"

namespace xte {
	template<typename T>
	constexpr auto destroy(T& object) XTE_ARROW(
		object.~T()
	);
}

#endif
