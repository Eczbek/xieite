#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CP_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CP_CTOR
#
#	include <type_traits>
#	include "../trait/set_cp_ctor.hpp"

namespace xieite {
	template<typename T>
	using cp_cp_ctor = xieite::set_cp_ctor<std::is_copy_constructible_v<T>>;
}

#endif
