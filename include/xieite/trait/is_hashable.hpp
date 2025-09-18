#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_HASHABLE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_HASHABLE
#
#	include <cstddef>
#	include <functional>
#	include "../trait/is_lref_invoc.hpp"

namespace xieite {
	template<typename T, typename Hasher = std::hash<T>>
	concept is_hashable = xieite::is_lref_invoc<Hasher, std::size_t(T)>;
}

#endif
