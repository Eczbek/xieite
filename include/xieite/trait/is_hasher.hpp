#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_HASHER
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_HASHER
#
#	include <cstddef>
#	include "../trait/is_invoc.hpp"

namespace xieite {
	template<typename T, typename Arg>
	concept is_hasher = xieite::is_invoc<T, std::size_t(Arg)>;
}

#endif
