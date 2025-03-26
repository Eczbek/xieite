#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_DEFAULT_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_DEFAULT_CTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_default_ctor = std::is_nothrow_default_constructible_v<T>;
}

#endif
