#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_DEFAULT_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_DEFAULT_CTOR
#
#	include <type_traits>
#	include "../trait/set_default_ctor.hpp"

namespace xieite {
	template<typename T>
	using cp_default_ctor = xieite::set_default_ctor<std::is_default_constructible_v<T>>;
}

#endif
