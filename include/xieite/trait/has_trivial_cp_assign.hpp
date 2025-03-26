#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_CP_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_CP_ASSIGN
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_cp_assign = std::is_trivially_copy_assignable_v<T>;
}

#endif
