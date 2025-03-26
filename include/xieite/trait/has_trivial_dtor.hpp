#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_DTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_DTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_dtor = std::is_trivially_destructible_v<T>;
}

#endif
