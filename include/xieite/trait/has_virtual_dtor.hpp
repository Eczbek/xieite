#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_VIRTUAL_DTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_VIRTUAL_DTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_virtual_dtor = std::has_virtual_destructor_v<T>;
}

#endif
