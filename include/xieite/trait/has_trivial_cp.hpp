#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_CP
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_CP
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_cp = std::is_trivially_copyable_v<T>;
}

#endif
