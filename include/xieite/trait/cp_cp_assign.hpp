#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CP_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CP_ASSIGN
#
#	include <type_traits>
#	include "../trait/set_cp_assign.hpp"

namespace xieite {
	template<typename T>
	using cp_cp_assign = xieite::set_cp_assign<std::is_copy_assignable_v<T>>;
}

#endif
